#include <bits/stdc++.h>
#define PB push_back
#define MAXN 10310
#define BOARD 10002
#define NSIZE 110
using namespace std;

typedef struct
{
    int to, cap, rev;
} NODE;
typedef pair<int, int> PII;
typedef vector< NODE > Net;
typedef vector< PII > G;

int N, M, K, P, ub, lb, md;
int input[NSIZE][2];
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
    int s=MAXN-2, t=MAXN-1;
    int flow=0;
    while(1) {
        bfs(s);
        if (level[t]<0) return flow;
        memset(iter, 0x00, sizeof(iter));
        int f;
        while((f=dfs(s,t,1e9+1))>0) {
            flow += f;
        }
    }
    return 0;
}

void add_edge(int from, int to, int cap) {
    graph[from].PB((NODE){to,cap,graph[to].size()});
    graph[to].PB((NODE){from, 0, graph[from].size()-1});
}

void rebuild(int target)
{
    //for(int i=0; i<MAXN; ++i) graph[i].clear();
    memset(graph,0x00,sizeof(graph));
    for(int i=0; i<BOARD; ++i) add_edge(MAXN-2, i, 1);
    int u, v;

    for(int i=0; i<N; ++i)
    {
        u = input[i][0]; v = input[i][1];
        for(int j=u; j<v; ++j)
        {
            add_edge(j, i+BOARD, 1);
        }
        add_edge(i+BOARD, MAXN-1, target);
    }
}

int main(void)
{
    int u, v, ans;
    bool succ;
    ub = lb = -1;
    scanf("%d", &N);
    for(int i=0; i<N; ++i)
    {
        scanf("%d%d", &u, &v);
        input[i][0] = u;
        input[i][1] = v;
        ub = max(ub, v);
    }
    lb = 0; ++ub;

    while(ub-lb>1)
    {
        md = (lb+ub)/2;
        rebuild(md);
        int temp;
        if((max_flow())==N*md)   //Success
        {
            lb = md;
            succ=true;
        }
        else ub = md;
        //printf("%d %d\n", lb, ub);
        //printf("# %d\n", temp);
    }

    //printf("%d\n",lb*N);
    printf("%d\n",succ?lb*N:0);
    return 0;
}