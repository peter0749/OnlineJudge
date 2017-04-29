#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>

using namespace std;
vector<int> Graph[10010];
bool vis[10010];
int par[10010];
int farp, depth;

void dfs(int u, int d) {
    vis[u]=true;
    if (d>depth) {
        depth = d;
        farp = u;
    }
    for (vector<int>::iterator it=Graph[u].begin(); it!=Graph[u].end(); ++it) {
        if (!vis[*it]) {
            par[*it]=u;
            dfs(*it, d+1);
        }
    }
}

int solv(int n) {
    depth = farp = 0;
    memset(vis,0x00,sizeof(vis));
    dfs(0, 0);
    depth = 0;
    memset(vis,0x00,sizeof(vis));
    for (int i=0; i<n; ++i) par[i]=-1;
    dfs(farp, 0);
    int d=0;
    int u=farp, v=par[farp];
    for (; v!=-1 && d<depth/2; v=par[u=v], ++d);
    if (depth&1) {
        u = min(u, par[u]==-1?INT_MAX:par[u]);
    }
    return u;
}

int main (void) {
    int T;
    //ios::sync_with_stdio(false);cin.tie(0);
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i=0; i<=n; ++i) Graph[i].clear();
        for (int i=0; i<n-1; ++i) {
            int u, v;
            cin>>u>>v;
            Graph[u].push_back(v);
            Graph[v].push_back(u);
        }
        cout << solv(n) << '\n';
    }
    return 0;
}
