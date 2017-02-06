#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 360

int arr[MAXN][MAXN];
int DP[MAXN][MAXN];

using namespace std;

int main(void){
    int N, sum, t;
    while(scanf("%d",&N)!=EOF && N){
        for(int i=0; i<N; ++i){
            for(int j=0; j<=i; ++j)
                scanf("%d",&arr[i][j]);
        }
        memset(DP,-1,sizeof(DP));
        DP[0][0]=arr[0][0];
        t = N-1;
        sum=-1;
        for(int i=0; i<t; ++i){
            for(int j=0; j<=i; ++j){
                DP[i+1][j] = max(DP[i+1][j], DP[i][j]+arr[i+1][j]);
                DP[i+1][j+1] = max(DP[i+1][j+1], DP[i][j]+arr[i+1][j+1]);
            }
        }
        for(int i=0; i<N; ++i) sum = max(sum, DP[N-1][i]);
        printf("%d\n",sum);
    }
    return 0;
}
