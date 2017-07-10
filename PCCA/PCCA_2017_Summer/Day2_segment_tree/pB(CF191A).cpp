#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
using namespace std;

const size_t MAXN=27;
const int inf=-1e9;
int dp[MAXN][MAXN];

int main(void) {
    int n;
    char s[4096], temp[4096];

    for (int i=0; i<MAXN; ++i) 
        for (int j=0; j<MAXN; ++j) 
            dp[i][j] = inf;

    fgets(temp, 4000, stdin);
    sscanf(temp,"%d", &n);
    for (int i=0; i<n; ++i) {
        fgets(temp, 4000, stdin);
        sscanf(temp,"%s", s);
        int from = s[0]-'a';
        int len  = strlen(s);
        int to   = s[ len-1 ]-'a';
        for (int j=0; j<MAXN; ++j) {
            if (dp[j][from]!=inf&&dp[j][from]+len>dp[j][to]) {
                //cout << j << ':' << to << '(' << dp[j][to];
                dp[j][to] = dp[j][from]+len;
                //cout << ") -> ";
                //cout << j << ':' << from << '(' << dp[j][from] << ") -> ";
                //cout << from << ':' << to << '(' << len << ")(new) -> ";
                //cout << j << ':' << to <<  '(' << dp[j][to] << ')' << endl;
            }
        }
        dp[from][to] = max(dp[from][to], len);
    }
    /*
    for (int i=0; i<MAXN; ++i) {
        for (int j=0; j<MAXN; ++j)
            //cout << setw(4) << (dp[i][j]==INT_MIN?-1:dp[i][j]) ;
        //cout << endl;
    }
    */
    int maxv=0;
    for (int i=0; i<MAXN; ++i) maxv=max(maxv, dp[i][i]);
    printf("%d\n", maxv);

    return 0;
}
