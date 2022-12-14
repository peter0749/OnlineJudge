class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int nRows = rooms.size();
        int nCols = rooms[0].size();

        const vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        deque<pair<int,int>> queue;

        for (int i=0; i<nRows; ++i)
            for (int j=0; j<nCols; ++j)
                if (rooms[i][j]==0)
                    queue.push_front({i,j});
        while (!queue.empty()) {
            auto top = queue.back();
            queue.pop_back();
            int i = top.first, j = top.second;
            for (int k=0; k<4; ++k) {
                int ni = i + dir[k].first;
                int nj = j + dir[k].second;
                if (ni<0 || nj<0 || ni>=nRows || nj>=nCols)
                    continue;
                if (rooms[ni][nj] == INT_MAX) {
                    queue.push_front({ni, nj});
                    rooms[ni][nj] = rooms[i][j] + 1;
                }
            }
        }
    }
};
