#pragma GCC optimize ("Os")
#include <bits/stdc++.h>
using namespace std;

const size_t MAXN = 10000100;
long long int dp[MAXN]; // 0: add , 1: copy

int main(void) {
    int n, x, y;
    cin >> n >> x >> y;
    memset(dp, 0x00, sizeof(dp));
    dp[0] = INT_MAX;
    dp[1] = x;
    for (int i=2; i<=n; ++i) {
        long long int first = dp[i-1]+(long long int)x;
        long long int second;
        if (i%2==0) second = dp[i/2]+(long long int)y;
        else {
            second = min(dp[(i-1)/2], dp[(i+1)/2])+(long long int)y+(long long int)x;
            //second = dp[(i-1)/2]+(long long int)x+(long long int)y;
        }
        dp[i] = min(first,second);
    }
    cout << dp[n] << endl;
    return 0;
}