#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int DP[1000100];

int main(void){
    int N;
    memset(DP,0x00,sizeof(DP));
    DP[1]=1; DP[2]=2; DP[3]=2;
    for(int i=4; i<=1000000; ++i){
        DP[i] = (DP[i/2] + DP[i&1?i-3:i-1])%1000000000;
    }
    while(scanf("%d",&N)!=EOF){
        printf("%d\n",DP[N]);
    }
    return 0;
}
