#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

const size_t MAXN(20);
int opt[MAXN][MAXN], tile[MAXN][MAXN], flip[MAXN][MAXN];
const int dx[] = {0,1,0,-1,0};
const int dy[] = {0,0,1,0,-1};
int N, M;

void init(void) {
    memset(tile,0x00,sizeof(tile));
    cin >> M >> N;
    for (int i=0; i<M; ++i) for (int j=0; j<N; ++j) {
        cin >> tile[i][j];
    }
}

int getAlive(const int x, const int y) {
    int counter=tile[y][x];
    for (int d=0; d<5; ++d) {
        int nx = x+dx[d];
        int ny = y+dy[d];
        if (0<=nx && nx<N && 0<=ny && ny<M) {
            counter += flip[ny][nx];
        }
    }
    return counter&1;
}

int testTile(void) {
    for (int i=1; i<M; ++i) {
        for (int j=0; j<N; ++j) {
            if (getAlive(j, i-1)) flip[i][j]=1;
        }
    }
    for (int i=0; i<N; ++i) {
        if (getAlive(i, M-1)) return -1;
    }
    int res=0;
    for (int i=0; i<M; ++i) {
        for (int j=0; j<N; ++j) {
            res += flip[i][j];
        }
    }
    return res;
}

void solv(void) {
    int res = -1;
    for (int i=0; i< (1<<N); ++i) {
        memset(flip,0x00,sizeof(flip)); // no big deal, just remember to initialize it.
        for (int j=0; j<N; ++j) flip[0][N-j-1] = (i>>j)&1; // iterate over all combination
        int test = testTile();
        if (test>=0 && (res==-1 || test<res)) {
            res = test;
            memcpy(opt, flip, sizeof(flip));
        }
    }
    if (res==-1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int i=0; i<M; ++i) {
        for (int j=0; j<N; ++j) {
            cout << opt[i][j] << (j==N-1?'\n':' ');
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    solv();
    return 0;
}