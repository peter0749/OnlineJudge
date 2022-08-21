class Solution {
public:
    // To iterate is human, to recursive, divine!
    // Runtime 10 ms
    bool validPlacement(int *board, int index, int pos) {
        for (int i=0; i<index; ++i) {
            if (board[i]==pos || abs(board[i]-pos) == index-i)
                return false;
        }
        return true;
    }
    int totalNQueens(int n) {
        int *board = new int[n];
        fill(board, board+n, -1);
        int total_solutions = 0;
        
        stack<tuple<int,int>> stk; // index, placement
        stk.push(tuple<int,int>({0, 0}));
        while (!stk.empty()) {
            int index, pos;
            tie(index, pos) = stk.top();
            bool bValidPlacement = validPlacement(board, index, pos);
            if (!bValidPlacement || board[index] != -1) {
                stk.pop();
                if (pos+1 < n)
                    stk.push(tuple<int,int>({index, pos+1})); // try next pos
                board[index] = -1; // backtrack
                continue;
            }
            board[index] = pos;
            
            // A solution found!
            if (index == n-1) {
                ++total_solutions;
                stk.pop();
                board[index] = -1; // backtrack
                continue;
            }
            
            stk.push(tuple<int,int>({index+1, 0}));
        }
        
        delete[] board; board = NULL;
        return total_solutions;
    }
};
