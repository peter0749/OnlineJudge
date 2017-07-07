#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>
#include <queue>
#define PB push_back
#define MAXN 500
#define BOARD 150
#define NSIZE 110
using namespace std;

struct NODE
{
    NODE(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {} 
    int to, cap, rev;
};
typedef vector< NODE > Net;

const int S=MAXN-2, T=MAXN-1;
int N, F, D;
Net graph[MAXN];//0~10000, 10001~10100
int level[MAXN];
int iter[MAXN];

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int i=0; i<graph[v].size(); ++i) {
            NODE &e = graph[v][i];
            if(e.cap >0 && level[e.to]<0) {
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if(v==t) return f;
    for(int &i = iter[v]; i<graph[v].size(); ++i) {
        NODE &e = graph[v][i];
        if(e.cap >0 && level[v]< level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if( d> 0) {
                e.cap -= d;
                graph[e.to][e.rev].cap +=d ;
                return d;
            }
        }
    }
    return 0;
}

int max_flow()
{
    int flow=0;
    while(1) {
        bfs(S);
        if (level[T]<0) return flow;
        memset(iter, 0x00, sizeof(iter));
        int f;
        while((f=dfs(S,T,1e9+1))>0) {
            flow += f;
        }
    }
    return 0;
}

void add_edge(int from, int to, int cap) {
    graph[from].PB(NODE(to,cap,graph[to].size()));
    graph[to].PB(NODE(from, 0, graph[from].size()-1));
}

void build() {
    // food: [0,F); drink: [F,F+D); last 2 S, T; ow: cow
    // cow1: [F+D, F+D+N); cow2: [F+D+N, )
#define F_BASE(i) i
#define D_BASE(i) F+i
#define N1_BASE(i) F+D+i
#define N2_BASE(i) F+D+N+i

    for (int i=0; i<F; ++i) {
        add_edge(S, F_BASE(i), 1); // source -> food 
    }
    for (int i=0; i<D; ++i) {
        add_edge(D_BASE(i), T, 1); // drink -> target
    }
    for (int i=0; i<N; ++i) { // cow
        int f, d;
        scanf("%d%d", &f, &d);
        for (int j=0; j<f; ++j) { // food -> cow1
            int t; scanf("%d", &t);
            add_edge(F_BASE(t-1), N1_BASE(i), 1); // 1-base -> 0-base
        }
        add_edge(N1_BASE(i), N2_BASE(i), 1);
        for (int j=0; j<d; ++j) { // cow -> drink
            int t; scanf("%d", &t);
            add_edge(N2_BASE(i), D_BASE(t-1), 1); // 1-base -> 0-base
        }
    }
#undef F_BASE
#undef D_BASE
#undef N1_BASE
#undef N2_BASE
}

void cleanup() {
    for (int i=0; i<MAXN; ++i) graph[i].clear();
}

int main(void) {
    while (scanf("%d%d%d", &N, &F, &D)==3) {
        build();
        printf("%d\n", max_flow());
        cleanup();
    }
    return 0;
}
