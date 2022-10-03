class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i=1; i<triangle.size(); ++i)  {
            for (int j=0; j<triangle[i].size(); ++j) {
                if (j==0)
                    triangle[i][j] += triangle[i-1][j];
                else if (j==triangle[i].size()-1)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        int minval = INT_MAX;
        int last = triangle.size()-1;
        for (int i=0; i<triangle[last].size(); ++i)
            minval = min(minval, triangle[last][i]);
        return minval;
    }
};
