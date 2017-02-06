#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int DP[40001];
int input[40001];

int main(void){
    int N, n;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&n);
        for(int i=0; i<n; ++i) scanf("%d", input+i);
        fill(DP,DP+n,1e9);
        for(int i=0; i<n; ++i){
            *lower_bound(DP, DP+n, input[i]) = input[i];
        }
        printf("%d\n",lower_bound(DP,DP+n,1e9) - DP);
    }
    return 0;
}
