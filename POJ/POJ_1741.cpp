#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXN 10011
#define INF 2000005000
using namespace std;

typedef vector<int> C;
typedef struct { int to, len; } EDGE;
vector< EDGE > graph[MAXN];
int ans;
int subtsize[MAXN];
bool cent[MAXN];
int ub, N, T;

int comp_subt(int v, int p) {
    int c=1;
    for(int i=0; i<graph[v].size(); ++i) { // Foreach edge of v
        int w = graph[v][i].to;
        if(w==p || cent[w]) continue; //if neighbor w == cent[w]
        c+=comp_subt(w,v); //accumulate
    }
    subtsize[v] = c;
    return c;
}

pair<int, int> search_cent(int v, int p, int t) { //t is the size of connected-component
    pair<int, int> res = make_pair(INF, -1);
    int s=1, m=0;
    for(int i=0; i<graph[v].size(); ++i) {
        int w = graph[v][i].to;
        if(w==p || cent[w]) continue;
        res = min(res, search_cent(w,v,t));
        m = max(m, subtsize[w]);
        s+=subtsize[w];
    }
    m = max(m, t-s);
    res = min(res, make_pair(m, v));
    return res;
}

void enum_path(int v, int p, int d, C &ds) { //Foreach path from v
    ds.push_back(d);
    for(int i=0; i<graph[v].size(); ++i) {
        int w = graph[v][i].to;
        if(w==p || cent[w]) continue;
        enum_path(w,v, d+graph[v][i].len, ds);
    }
}

int count_pii(C &ds) {
    int res = 0;
    sort(ds.begin(), ds.end());
    int j = ds.size();
    for(int i=0; i<ds.size(); ++i) {
        while(j>0 && ub < ds[i] + ds[j-1]) --j;
        res += (j - (j>i ? 1:0)); //del self-pair
    }
    return res/2;
}

int solv_sub(int v) {
    comp_subt(v, -1);
    int s = search_cent(v, -1, subtsize[v]).second;
    cent[s] = true;
    for(int i=0; i<graph[s].size(); ++i) {
        if(cent[graph[s][i].to]) continue;
        solv_sub(graph[s][i].to);
    }
    C ds;
    ds.push_back(0);
    for(int i=0; i<graph[s].size(); ++i) {
        if(cent[graph[s][i].to]) continue;
        C tds;
        enum_path(graph[s][i].to, s, graph[s][i].len, tds);
        ans-=count_pii(tds);
        ds.insert(ds.end(), tds.begin(), tds.end()); //append tds after ds
    }
    ans+=count_pii(ds);
    cent[s] = false;
}

int solv(int n) {
    memset(cent,0x00,sizeof(cent));
    memset(subtsize, 0x00, sizeof(subtsize));
    ans = 0;
    solv_sub(n);
    return ans;
}

inline void biconnect_node(int &u, int &v, int &w) {
    if(u==v) return;
    graph[u].push_back((EDGE){v,w});
    graph[v].push_back((EDGE){u,w});
}

int main(void) {
    int u, v, w, minno;
    while(scanf("%d%d", &N, &ub)==2 && N) {
        for(int i=0; i<MAXN; ++i) graph[i].clear();
        minno=INF;
        --N;
        while(N--) {
            scanf("%d%d%d", &u, &v, &w);
            minno = min(minno, u);
            biconnect_node(u,v,w);
        }
        printf("%d\n", solv(minno));
    }
    return 0;
}
