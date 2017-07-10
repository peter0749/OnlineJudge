#include <bits/stdc++.h>
using namespace std;

const size_t MAXN(1e5+10);
int data[MAXN];
int dp[MAXN][2];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) scanf("%d", data+i);
    int sum=0;
    int evensum=0, oddsum=-1e9+1;
    for (int i=0; i<n; ++i) {
        sum+=(!(data[i]&1)&&data[i]>0)?data[i]:0; // input is even and > 0
        if (data[i]&1) { // input is odd
            int evenp = data[i]+evensum;
            int oddp  = data[i]+oddsum; // if first, select one
            evensum = max(evensum, oddp);
            oddsum  = max(oddsum ,evenp);
        }
    }
    //printf("%d %d %d\n", oddsum, evensum, sum);
    printf("%d\n",oddsum+sum);
    return 0;
}
