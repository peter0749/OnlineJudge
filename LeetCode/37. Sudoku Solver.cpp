class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // initialization
        bool rowSet[9][10] = {false};
        bool colSet[9][10] = {false};
        bool cellSet[3][3][10] = {false};
        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                if (board[i][j]=='.') continue;
                rowSet[i][board[i][j]-'0'] = true;
                colSet[j][board[i][j]-'0'] = true;
                cellSet[i/3][j/3][board[i][j]-'0'] = true;
            }
        }
        stack<tuple<int,int>> stk;
        vector<tuple<int,int>> empty_pos;
        for (int i=0; i<9; ++i)
            for (int j=0; j<9; ++j)
                if (board[i][j]=='.')
                    empty_pos.push_back(tuple<int,int>({i,j}));
        stk.push(tuple<int,int>({0,1}));
        while (!stk.empty()) {
            int i, j, level, num;
            tie(level,num) = stk.top();
            tie(i,j) = empty_pos[level];
            
            // invalid
            if (rowSet[i][num] || colSet[j][num] || cellSet[i/3][j/3][num]) {
                stk.pop();
                if (board[i][j]!='.') {
                    int oldv = board[i][j]-'0';
                    rowSet[i][oldv] = false;
                    colSet[j][oldv] = false;
                    cellSet[i/3][j/3][oldv] = false;
                    board[i][j] = '.';
                }
                if (num+1<=9) {
                    stk.push(tuple<int,int>({level,num+1}));
                }
                continue;
            }
            
            rowSet[i][num] = true;
            colSet[j][num] = true;
            cellSet[i/3][j/3][num] = true;
            board[i][j] = '0'+num;
            
            if (level==empty_pos.size()-1) break;
            stk.push(tuple<int,int>({level+1,1}));
        }
    }
};
