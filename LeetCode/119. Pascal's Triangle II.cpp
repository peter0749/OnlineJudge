class Solution {
public:
    vector<int> dp[2];
    vector<int> getRow(int rowIndex) {
        dp[0] = {1};
        dp[1] = {1,1};
        for (int i=2; i<=rowIndex; ++i) {
            vector<int> &curr = dp[i&1];
            vector<int> &prev = dp[(i-1)&1];
            curr.clear();
            curr.push_back(1);
            for (int j=1; j<prev.size(); ++j)
                curr.push_back(prev[j-1]+prev[j]);
            curr.push_back(1);
        }
        return dp[rowIndex&1];
    }
};
