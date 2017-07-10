#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
using namespace std;

const int dirv[4][2] = { {0,-1},{1,0},{0,1},{-1,0} }; // U, R, D, L
const char dirc[4] = { 'U','R','D','L' }; // U, R, D, L
char FLOOR[16][16];
int rec[16][16];

int N, M;

int brute(int u, int v, int enterDir) { // x, y, dir, ret = loop to inf
    memset(rec, 0x00, sizeof(rec));
    while(true) {
        int nu = u + dirv[enterDir][0]; // next x
        int nv = v + dirv[enterDir][1]; // next y
        //cout << u << ' ' << v << endl;
        ++rec[v][u];
        if (rec[v][u]==6) break;
        if (FLOOR[nv][nu]=='.') { 
            u=nu, v=nv; continue;
        }
        enterDir = (enterDir+1)%4;
    }
    int sum = 0;
    for (int i=1; i<=N; ++i) for (int j=1; j<=M; ++j) sum += (rec[i][j]>0);
    return sum; // loop size
}

#define RL() fgets(buf, 100, stdin)

int main(void) {
    int ex, ey, edir;
    char buf[128];
    RL();
    sscanf(buf,"%d%d", &N, &M);
    for (int i=0; i<=N+1; i++)for (int j=0; j<=M+1; ++j) FLOOR[i][j] = '*';
    for (int i=1; i<=N; ++i) {
        RL();
        for (int j=1; j<=M; ++j) {
            FLOOR[i][j] = buf[j-1];
            for (int k=0; k<4; ++k) {
                if (FLOOR[i][j]==dirc[k]) {
                    ey = i;
                    ex = j;
                    edir = k;
                    FLOOR[i][j] = '.';
                }
            }
        }
    }
    printf("%d\n", brute(ex, ey, edir));
    return 0;
}
