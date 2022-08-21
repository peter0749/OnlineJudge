class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        // Rotation 90 degree = transpose + mirror (swap cols)
        // Or = mirror (swap rows) + transpose => faster
        
        // Mirror (rows)
        reverse(matrix.begin(), matrix.end());
        // Transpose
        for (int i=0; i<N; ++i)
            for (int j=i+1; j<N; ++j) {
                swap(matrix.at(i).at(j), matrix.at(j).at(i));
            }
    }
};
