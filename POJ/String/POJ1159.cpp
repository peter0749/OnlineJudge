#pragma GCC optimize("O3")
#pragma GCC target ("avx")
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

unsigned short dp[2][5010]; // 滾動陣列
int N;
string s;

inline int solv() {
    memset(dp, 0x00, sizeof(dp));
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            if (s[i-1]==s[N-j]) dp[i&1][j] = dp[(i-1)&1][j-1]+1;
            else {
                dp[i&1][j] = max(dp[(i-1)&1][j], dp[i&1][j-1]);
            }
        }
    }
    return N-(int)max(dp[1][N],dp[0][N]);
}

int main(void) {
    cin >> N;
    cin >> s;
    cout << solv() << endl;
    return 0;
}
