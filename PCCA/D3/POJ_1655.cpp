#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXN 20011
#define INF 2000005000
using namespace std;

typedef vector<int> C;
typedef struct { int to, len; } EDGE;
vector< EDGE > graph[MAXN];
int ans;
int subtsize[MAXN];
int ub, N, T;

int comp_subt(int v, int p) {
    int c=1;
    for(int i=0; i<graph[v].size(); ++i) { // Foreach edge of v
        int w = graph[v][i].to;
        if(w==p) continue; //if neighbor w == cent[w]
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
        if(w==p) continue;
        res = min(res, search_cent(w,v,t));
        m = max(m, subtsize[w]);
        s+=subtsize[w];
    }
    m = max(m, t-s);
    res = min(res, make_pair(m, v));
    return res;
}

pair<int, int> solv_sub(int v) {
    comp_subt(v, -1);
    return search_cent(v, -1, subtsize[v]);
}

pair<int, int> solv(int n) {
    memset(subtsize, 0x00, sizeof(subtsize));
    return solv_sub(n);
}

inline void biconnect_node(int &u, int &v, int &w) {
    if(u==v) return;
    graph[u].push_back((EDGE){v,w});
    graph[v].push_back((EDGE){u,w});
}

int main(void) {
    int u, v, w, minno;
    scanf("%d", &T);
    while(T--) {
        for(int i=0; i<MAXN; ++i) graph[i].clear();
        minno=INF;
        scanf("%d", &N);--N;
        while(N--) {
            scanf("%d%d", &u, &v);
            minno = min(minno, u);
            biconnect_node(u,v,w);
        }
        pair<int, int> res = solv(minno);
        printf("%d %d\n", res.second, res.first);
    }
    return 0;
}
