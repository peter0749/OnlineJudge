class Solution {
public:
    // O(N^2) solution...
    int LCS(vector<int>& num1, vector<int>& num2) {
        vector<vector<int> > dp(num1.size()+1, vector<int>(num2.size()+1, 0));
        for (int i=1; i<=num1.size(); ++i) {
            for (int j=1; j<=num2.size(); ++j) {
                dp[i][j] = dp[i-1][j-1] + (num1[i-1]==num2[j-1]?1:0);
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
        return dp[num1.size()][num2.size()];
    }
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        if (N==1) return 1;
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        auto it = unique(sorted.begin(), sorted.end());
        sorted.resize(distance(sorted.begin(), it));
        return LCS(nums, sorted);
    }
};
