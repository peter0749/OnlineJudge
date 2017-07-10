#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
using namespace std;

const size_t MAXN=105;
int graph[MAXN][MAXN];
int col[MAXN];
int opt[MAXN];
int maxblack=0;

void brute(int u, int select, int n) {
    if (n-u+select<=maxblack || u>=n) {
        if (select>maxblack) {
            memcpy(opt, col, sizeof(col));
            maxblack = select;
        }
        return;
    }
    bool conflict = false;
    for (int i=0; i<n && !conflict; ++i) 
        if (graph[u][i] && col[i]) conflict = true;
    if (!conflict) {
        col[u] = 1;
        brute(u+1, select+1, n);
        col[u] = 0;
    }
    brute(u+1, select, n);
}

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(graph, 0x00, sizeof(graph));
        for (int i=0; i<m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            graph[u-1][v-1]=1;
            graph[v-1][u-1]=1;
        }
        maxblack = 0;
        memset(col, 0x00, sizeof(col));
        brute(0,0,n);

        printf("%d\n", maxblack);
        bool first=true;
        for (int i=0; i<n; ++i) {
            if (opt[i]) {
                if (!first) printf(" ");
                first = false;
                printf("%d", i+1);
            }
        }
        printf("\n");
    }
    return 0;
}
