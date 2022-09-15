/*
 * In-place modification with bit manipulation
 */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j) {
                int cnt = 0;
                for (int di=-1; di<=1; ++di)
                    for (int dj=-1; dj<=1; ++dj) {
                        int r = i+di, c = j+dj;
                        if (!(di==0&&dj==0) && r>=0 && r<m && c>=0 && c<n && board[r][c]&1)
                            ++cnt;
                    }
                if (board[i][j]&1) {
                    if (cnt>=2 && cnt<=3) board[i][j] |= 2;
                } else {
                    if (cnt==3) board[i][j] |= 2;
                }
            }
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                board[i][j] >>= 1;
    }
};
