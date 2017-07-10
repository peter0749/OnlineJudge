#include <bits/stdc++.h>
using namespace std;
int N, M;
int grid[200][200];
int rec [200][200]; 
int dirv[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int maxd=0;

void dfs(int u, int v, int d) {
    if (d <= rec[u][v]) return; // no improvment is possible
    maxd = max(maxd, d);
    rec[u][v] = d;
    for (int i=0; i<4; ++i) {
        int nu = u+dirv[i][0];
        int nv = v+dirv[i][1];
        if (grid[nu][nv]<grid[u][v])
            dfs(nu,nv,d+1);
    }
}

int main(void) {
    int term;
    string name;
    cin >> term;
    while(term--) {
        cin >> name >> N >> M;
        for (int i=N+10; i>=0; --i) for (int j=M+10; j>=0; --j) grid[i][j] = 1e9;
        memset(rec, -1, sizeof(rec));
        for (int i=1; i<=N; ++i) for (int j=1; j<=M; ++j) cin >> grid[i][j];
        maxd = 0;
        for (int i=1; i<=N; ++i) {
            for (int j=1; j<=M; ++j) {
                dfs(i, j, 1);
            }
        }
        cout << name << ": " << maxd << '\n';
    }

    return 0;
}
