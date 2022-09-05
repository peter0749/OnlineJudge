class Solution {
public:
    // Solution using stack
    // Runtime 12 ms
    bool validPlacement(int *board, int index, int pos) {
        for (int i=0; i<index; ++i) {
            if (board[i]==pos || abs(board[i]-pos) == index-i)
                return false;
        }
        return true;
    }
    vector<string> decode(int *board, int n) {
        vector<string> ret;
        for (int i=0; i<n; ++i) {
            string s(n,'.');
            s[board[i]] = 'Q';
            ret.push_back(s);
        }
        return ret;
    }
    void print(int *board, int n) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j)
                cout << (board[i]==j?'Q':'.');
            cout << endl;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int *board = new int[n];
        fill(board, board+n, -1);
        vector<vector<string>> solution;
        
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
                solution.push_back(decode(board, n));
                stk.pop();
                board[index] = -1; // backtrack
                continue;
            }
            
            stk.push(tuple<int,int>({index+1, 0}));
        }
        
        delete[] board; board = NULL;
        return solution;
    }
};
