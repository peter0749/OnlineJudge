#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
using namespace std;

int N, M;
int YEE[30][30];

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d",&N,&M);
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j)
                scanf("%d",&YEE[i][j]);
        }
        bool succ=true;
        for (int i=0; i<N && succ; ++i) {
            for (int j=0; j<M && succ; ++j) {
                if (YEE[i][j]!=YEE[N-1-i][M-1-j]) succ=false;
            }
        }
        printf(succ?"go forward\n":"keep defending\n");
    }
    return 0;
}
