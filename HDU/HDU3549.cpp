#pragma GCC target ("avx")
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define PB push_back
using namespace std;

struct NODE
{
    NODE(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
    int to, cap, rev;
};
typedef vector< NODE > Net;

const size_t MAXN = 2000;
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

int max_flow(int S, int T)
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

void clear() {
    for (int i=0; i<MAXN; ++i) graph[i].clear();
}

int main(void) {
    int T;
    cin >> T;
    for (int i=1; i<=T; ++i) {
        int N, M;
        cin >> N >> M;
        clear();
        for (int i=0; i<M; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            add_edge(a,b,c);
        }
        cout << "Case " << i << ": " << max_flow(1,N) << endl;
    }
    return 0;
}