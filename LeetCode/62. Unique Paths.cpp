class Solution {
public:
    int dp[2][100];
    int uniquePaths(int m, int n) {
        // 1 1 1  1  1  1
        // 1 2 3  4  5  6
        // 1 3 6 10 15 21
        // dp[m,n] = dp[m-1,n] + dp[m,n-1]
        // can be simplify to rolling dp to save space
        fill(dp[0], dp[0]+n, 1);
        for (int i=1; i<m; ++i) {
            dp[i&1][0] = 1;
            for (int j=1; j<n; ++j)
                dp[i&1][j] = dp[(i-1)&1][j] + dp[i&1][j-1];
        }
        return dp[(m-1)&1][n-1];
    }
};
