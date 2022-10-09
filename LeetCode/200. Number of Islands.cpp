class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return;
        if (grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int N = grid.size();
        int M = grid[0].size();
        for (int i=0; i<N; ++i)
            for (int j=0; j<M; ++j)
                if (grid[i][j]=='1') {
                    ++cnt;
                    dfs(i, j, grid);
                }
        return cnt;
    }
};
