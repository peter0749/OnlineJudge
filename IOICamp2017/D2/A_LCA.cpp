#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int UT;

const int MAXN=100010;
UT sz[MAXN];
vector<int> g[MAXN];

UT dfs(int u) {
    UT size=1;//self
    for(int i=0; i<g[u].size(); ++i) {
        size += dfs(g[u][i]);
    }
    return (sz[u]=size);
}

int main(void) {
    int T, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=2; i<=n; ++i) {
            int v;
            scanf("%d",&v);
            g[v].push_back(i);
        }
        dfs(1);
        //for(int i=1; i<=n; ++i) printf("?? %lld\n", sz[i]);
        
        for(int i=1; i<=n; ++i) {
            if(i!=1) putchar(' ');
            UT X = sz[i]-1, sum;
            sum = X*2+1;
            for(int j=0; j<g[i].size(); ++j) {
                sum +=( (X-sz[g[i][j]])*sz[g[i][j]] );
            }
            printf("%lld",sum);
        }
        puts("");
        for(int i=0; i<=n; ++i) g[i].clear();
    }
    return 0;
}
