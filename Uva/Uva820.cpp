#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
#define PB push_back
#define MAXN 300
using namespace std;

typedef struct
{
    int to;
    long long int cap;
    int rev;
} NODE;
typedef vector< NODE > Net;

Net graph[MAXN];//0~10000（正邊）, 10001~10100（反邊）
int level[MAXN];
int iter[MAXN];

inline long long int lmax(const long long int &a, const long long int &b) { 
    return a<b?b:a;
}

inline long long int lmin(const long long int &a, const long long int &b) { 
    return a<b?a:b;
}

inline void init(int n) {
    memset(graph, 0x00, sizeof(graph[0])*(n+1));
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int i=0; i<graph[v].size(); ++i) {
            NODE &e = graph[v][i];
            if(e.cap >0L && level[e.to]<0) {
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }
}

long long int dfs(int v, int t, long long int f) {
    if(v==t) return f;
    for(int &i = iter[v]; i<graph[v].size(); ++i) {
        NODE &e = graph[v][i];
        if(e.cap >0L && level[v]< level[e.to]) {
            long long int d = dfs(e.to, t, lmin(f, e.cap));
            if( d> 0L) {
                e.cap -= d;
                graph[e.to][e.rev].cap +=d ;
                return d;
            }
        }
    }
    return 0L;
}

long long int max_flow(int s, int t)
{
    long long int flow=0;
    while(1) {
        bfs(s);
        if (level[t]<0) return flow;
        memset(iter, 0x00, sizeof(iter));
        long long int f;
        while((f=dfs(s,t,9000000000000000000LL))>0L) {
            flow += f;
        }
    }
    return 0;
}

void add_edge(int from, int to, long long int cap) {
    graph[from].PB((NODE){to,cap,(int)graph[to].size()});
    graph[to].PB((NODE){from, 0L, (int)(graph[from].size()-1)});
}

#define RL() fgets(buffer, 4000, stdin)

int main(void) {
    char buffer[4096];
    int nNum=0 , cases=0;
    int source, target, eNum;
    while(1) {
        RL();
        sscanf(buffer, "%d", &nNum); 
        if (!nNum) break;
        init(nNum);
        RL();
        sscanf(buffer, "%d%d%d", &source, &target, &eNum);
        for (int i=0; i<eNum; ++i) {
            int s, t;
            long long int c;
            RL();
            sscanf(buffer, "%d%d%lld", &s, &t, &c);
            add_edge(s, t, c);
            add_edge(t, s, c);
        }
        printf("Network %d\n", ++cases);
        printf("The bandwidth is %lld.\n\n", max_flow(source, target));
    }
    return 0;
}
