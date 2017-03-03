#include <iostream>
#include <string>
#include <queue>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int scale=105;
const int INF=1e9+7;
int gra[scale][scale];
int N;
bool used[scale];
int d[scale];

int prim() {
    typedef pair<int, int> IPI; //weight, node
    fill(used, used+N, false);
    fill(d, d+N, INF);
    int total=0;
    d[0]=0;
    for(;;) {
        int v=-1;
        for(int u=0; u<N; ++u) {
            if(!used[u] && (v==-1 || d[u]<d[v])) v=u;
        }
        if(v==-1)break; // All good
        used[v]=true;
        total+=d[v];
        for(int u=0; u<N; ++u) {
            d[u] = min(d[u], gra[v][u]);
        }
    }
    return total;
}

int main(void) {
    while( scanf("%d",&N)==1) {
        for(int i=0; i<N; ++i) for(int j=0; j<N; ++j)
            scanf("%d",&gra[i][j]);
        printf("%d\n", prim());
    }
    return 0;
}
