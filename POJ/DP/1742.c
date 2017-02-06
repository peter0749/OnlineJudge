#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100010

int DP[MAXN], A[MAXN], C[MAXN];

int main(void){
    int i, j, n, m, count;
    while(scanf("%d%d",&n,&m)==2&&n&&m){
        for(i=0; i<n;++i) scanf("%d",A+i);
        for(i=0; i<n;++i) scanf("%d",C+i);
        memset(DP,-1,sizeof(DP));
        DP[0] = 0;
        for(i=0; i<n; ++i){
            for(j=0; j<=m; ++j){
                if(DP[j]>=0){
                    DP[j]=C[i];
                }else if(j<A[i] || DP[j-A[i]] <=0){
                    DP[j]=-1;
                }else{
                    DP[j]=DP[j-A[i]]-1;
                }
            }
        }
        count=0;
        for(i=1; i<=m; ++i) if(DP[i]>=0)++count;
        printf("%d\n", count);
    }
    return 0;
}
