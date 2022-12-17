class Solution {
public:
    const vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(int i, int j, vector<vector<int>>& grid, int &maxVal, int sum=0) {
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return;
        sum += grid[i][j];
        maxVal = max(maxVal, sum);
        int backtrack = grid[i][j];
        grid[i][j] = 0;
        for (int k=0; k<4; ++k) {
            dfs(i+dirs[k][0],j+dirs[k][1], grid, maxVal, sum=sum);
        }
        grid[i][j] = backtrack;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxVal = 0;
        for (int i=0; i<grid.size(); ++i)
            for (int j=0; j<grid[0].size(); ++j)
                dfs(i, j, grid, maxVal, 0);
        return maxVal;
    }
};
