#pragma GCC optimize("Os")
#pragma GCC target ("avx")
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

unsigned short dp[5010][5010];
int N;
string s;

inline int solv() {
    memset(dp, 0x00, sizeof(dp));
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            if (s[i-1]==s[N-j]) dp[i][j] = dp[i-1][j-1]+1;
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int maxv=0;
    for (int i=1; i<=N; ++i) for (int j=1; j<=N; ++j) maxv=max(maxv,(int)dp[i][j]);
    return N-maxv;
}

int main(void) {
    cin >> N;
    cin >> s;
    cout << solv() << endl;
    return 0;
}
