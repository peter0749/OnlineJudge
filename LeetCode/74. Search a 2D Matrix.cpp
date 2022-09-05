class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m, n;
        m = matrix.size();
        n = matrix[0].size();
        int l = 0, r = m*n;
        // [l,r)
        while (r-l>1) {
            int p = l + (r-l) / 2;
            if (matrix[p/n][p%n] == target) return true;
            else if (matrix[p/n][p%n] < target)
                l = p + 1;
            else
                r = p;
        }
        return l/n<m && matrix[l/n][l%n] == target;
    }
};
