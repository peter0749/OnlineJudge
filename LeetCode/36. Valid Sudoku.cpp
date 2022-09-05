class Solution {
public:
    
    unordered_set<char> hashmap_uh;
    
    inline bool isColValid(vector<vector<char>>& board) {
        for (int i=0; i<9; ++i) {
            hashmap_uh.clear();
            for (int j=0; j<9; ++j) {
                if (board[i][j] != '.') {
                    if (hashmap_uh.count(board[i][j])!=0)
                        return false;
                    hashmap_uh.insert(board[i][j]);
                }
            }
        }
        return true;
    }
    
    inline bool isRowValid(vector<vector<char>>& board) {
        for (int i=0; i<9; ++i) {
            hashmap_uh.clear();
            for (int j=0; j<9; ++j) {
                if (board[j][i] != '.') {
                    if (hashmap_uh.count(board[j][i])!=0)
                        return false;
                    hashmap_uh.insert(board[j][i]);
                }
            }
        }
        return true;
    }
    
    inline bool isCellValid(vector<vector<char>>& board) {
        for (int cell_i=0; cell_i<3; ++cell_i) {
            for (int cell_j=0; cell_j<3; ++cell_j) {
                hashmap_uh.clear();
                for (int i=0; i<3; ++i) {
                    for (int j=0; j<3; ++j) {
                        int r = cell_i * 3 + i;
                        int c = cell_j * 3 + j;
                        if (board[r][c] != '.') {
                            if (hashmap_uh.count(board[r][c])!=0)
                                return false;
                            hashmap_uh.insert(board[r][c]);
                        }
                    }
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        return isColValid(board) && isRowValid(board) && isCellValid(board);
    }
};
