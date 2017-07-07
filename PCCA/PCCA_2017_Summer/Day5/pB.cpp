#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <queue>
#include <map>
#include <vector>
#define PB push_back
#define MAXN 2000
using namespace std;

struct NODE
{
    NODE(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
    int to, cap, rev;
};
typedef vector< NODE > Net;

int N, M, S, T;
map<int,int> s;
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
    const int &s=S, &t=T;
    int flow=0;
    while(1) {
        bfs(s);
        if (level[t]<0) return flow;
        memset(iter, 0x00, sizeof(iter));
        int f;
        while((f=dfs(s,t,INT_MAX-1))>0) {
            flow += f;
        }
    }
    return 0;
}

void add_edge(int from, int to, int cap) {
    graph[from].PB(NODE(to,cap,(int)graph[to].size()));
    graph[to].PB(NODE(from, 0, (int)(graph[from].size())-1));
}

void build(void)
{
    // M+N: source; M+N+1; target; [N,M+N): plaent, [0, N): people
    S = MAXN-1;
    T = MAXN-2;
    int P = MAXN-3-M; // start of index of planet

    // people -> plaent
    for (int i=0; i<N; ++i) {
        int status=0;
        for (int j=0; j<M; ++j) {
            int input;
            scanf("%d", &input);
            if (input) status |= (1<<j);
        }
        ++s[status];
    }
    for (map<int,int>::iterator v=s.begin(); v!=s.end(); ++v) {
        int u = v->first;
        int w = v->second;
        add_edge(S, u, w);
        int c=P, t=u;
        while(t) { 
            if (t&1) add_edge(u, c, w);
            t>>=1;
            ++c;
        }
    }
    s.clear();

    // plaent -> target
    for (int i=0; i<M; ++i) {
        int status=0;
        scanf("%d", &status);
        if (status)
            add_edge(i+P, T, status);
    }
}

inline void cleanup(void) {
    for (int i=0; i<MAXN; ++i) graph[i].clear();
}

int main(void)
{
    while(scanf("%d%d", &N, &M)==2 && N && M) {
        build();
        printf( max_flow()>=N? "YES\n":"NO\n");
        cleanup();
    }

    return 0;
}
