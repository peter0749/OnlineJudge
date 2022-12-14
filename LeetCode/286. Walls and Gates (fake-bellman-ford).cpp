class Solution {
private:
    const vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<tuple<int,int,int,int>> findEdges(vector<vector<int>>& rooms) {
        int nRows = rooms.size();
        int nCols = rooms[0].size();

        vector<tuple<int,int,int,int>> edges;
        for (int i=0; i<nRows; ++i) {
            for (int j=0; j<nCols; ++j) {
                if (rooms[i][j] <= 0)
                    continue;
                for (int k=0; k<4; ++k) {
                    int ni = i + directions[k][0];
                    int nj = j + directions[k][1];
                    if (ni < 0 || ni >= nRows || nj < 0 || nj >= nCols)
                        continue;
                    if (rooms[ni][nj] < 0)
                        continue;
                    edges.push_back({i, j, ni, nj});
                }
            }
        }
        return edges;
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int nRows = rooms.size();
        int nCols = rooms[0].size();
        vector<tuple<int,int,int,int>> edges = findEdges(rooms);
        for (int i=1; i<edges.size(); ++i) {
            bool improved = false;
            for (auto &e : edges) {
                int i, j, ni, nj;
                tie(i, j, ni, nj) = e;
                if (rooms[ni][nj] == INT_MAX)
                    continue;
                if (rooms[ni][nj]+1 < rooms[i][j]) {
                    rooms[i][j] = rooms[ni][nj]+1;
                    improved = true;
                }
            }
            if (!improved)
                break;
        }
    }
};
