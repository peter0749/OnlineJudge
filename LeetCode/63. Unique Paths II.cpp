class Solution {
public:
    int dp[2][100];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0])
            return 0;
        
        dp[0][0] = 1;
        for (int i=1; i<n; ++i) 
            dp[0][i] = obstacleGrid[0][i] ? 0 : dp[0][i-1];
        
        for (int i=1; i<m; ++i) {
            dp[i&1][0] = obstacleGrid[i][0] ? 0 : dp[(i-1)&1][0];
            for (int j=1; j<n; ++j) {
                dp[i&1][j] = obstacleGrid[i][j] ? 0 : (dp[(i-1)&1][j] + dp[i&1][j-1]);
            }
        }
        return dp[(m-1)&1][n-1];
    }
};
