class Solution {
public:
    /*
    0 1 2 0
    3 4 5 2
    1 3 1 5
    */
    inline bool isFirstColZero(vector<vector<int>>& matrix) {
        for (int i=0; i<matrix.size(); ++i)
            if (matrix[i][0] == 0)
                return true;
        return false;
    }
    inline bool isFirstRowZero(vector<vector<int>>& matrix) {
        for (int i=0; i<matrix[0].size(); ++i)
            if (matrix[0][i] == 0)
                return true;
        return false;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        bool bFirstColZero = isFirstColZero(matrix);
        bool bFirstRowZero = isFirstRowZero(matrix);
        for (int i=1; i<matrix.size(); ++i)
            for (int j=1; j<matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        for (int i=1; i<matrix.size(); ++i) {
            if (matrix[i][0] == 0)
                for (int j=1; j<matrix[0].size(); ++j)
                    matrix[i][j] = 0;
        }
        for (int j=1; j<matrix[0].size(); ++j) {
            if (matrix[0][j] == 0)
                for (int i=1; i<matrix.size(); ++i)
                    matrix[i][j] = 0;
        }
        if (bFirstColZero)
            for (int i=0; i<matrix.size(); ++i)
                matrix[i][0] = 0;
        if (bFirstRowZero)
            for (int j=0; j<matrix[0].size(); ++j)
                matrix[0][j] = 0;
    }
};
