#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1010
#define MAXW 40
#define max(X,Y) (X) > (Y) ? (X) : (Y)

int arr[MAXN];
int DP[MAXN][MAXW];

int main(void){
    int i, W, T, j, test, sum;
    while(scanf("%d%d", &T, &W)==2){
        for(i=0; i<T; ++i) scanf("%d",arr+i);
        memset(DP,-1,sizeof(DP));
        DP[0][0] = arr[0]==1;
        DP[0][1] = arr[0]==2;
        for(i=1; i<T; ++i){
            for(j=0; j<=W; ++j){
                test = (arr[i]==(j%2+1));
                DP[i][j]=max(DP[i][j],DP[i-1][j]+(test?1:0));
                DP[i][j+1]=max(DP[i][j+1], DP[i-1][j]+(test?0:1));
            }
        }
        sum = DP[T-1][0];
        for(i=1; i<=W; i++) sum = max(sum, DP[T-1][i]);
        printf("%d\n",sum);
    }
    return 0;
}
