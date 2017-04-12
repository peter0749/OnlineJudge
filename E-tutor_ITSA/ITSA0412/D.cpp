#include <bits/stdc++.h>
using namespace std;

int mtxA[20][20], mtxB[20][20];
int mtxC[20][20];

int main(void) {
    const size_t MAXN=3000;
    char buff[MAXN];
    int N;
    int m, v;
    fgets(buff, MAXN-1, stdin);
    N = atoi(buff);
    while(N--) {
        fgets(buff, MAXN-1, stdin);
        sscanf(buff,"%d%d", &m, &v);
        memset(mtxA,0x00,sizeof(mtxA));
        memset(mtxB,0x00,sizeof(mtxB));
        memset(mtxC,0x00,sizeof(mtxC));
        for (int i=0; i<v; ++i) {
            int a,b,c;
            fgets(buff, MAXN-1, stdin);
            sscanf(buff,"(%d:%d)=%d",&a,&b,&c);
            --a;--b; //zero-base
            mtxA[a][b]=c;
            mtxB[b][a]=c;
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<m; ++j) {
                for (int k=0; k<m; ++k) {
                    mtxC[i][j] += mtxA[i][k]*mtxB[k][j];
                }
            }
        }
        for (int i=0, j=0; i<m; ++i) {
            j = 0;
            printf("%d", mtxC[i][j]);
            for (j=1; j<m; ++j) {
                printf(" %d", mtxC[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
