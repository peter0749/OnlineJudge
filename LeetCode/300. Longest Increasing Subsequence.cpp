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

class Solution {
public:
    // O(NlgN) solution
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        if (N==1) return 1;
        vector<int> LIS;
        LIS.push_back(nums[0]);
        for (int i=1; i<nums.size(); ++i) {
            int index = distance(LIS.begin(), upper_bound(LIS.begin(), LIS.end(), nums[i]));
            if (index-1>=0 && index-1<LIS.size() && LIS[index-1]==nums[i])
                --index;
            if (index >= LIS.size())
                LIS.push_back(nums[i]);
            else
                LIS[index] = nums[i];
        }
        //for (auto v : LIS)
        //    cout << v << endl;
        return LIS.size();
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // O(NlgN) solution, only for getting maximal length
        int N = nums.size();
        if (N==1) return 1;
        vector<int> LIS;
        LIS.push_back(nums[0]);
        for (int i=1; i<nums.size(); ++i) {
            int index = distance(LIS.begin(), upper_bound(LIS.begin(), LIS.end(), nums[i]));
            if (index-1>=0 && index-1<LIS.size() && LIS[index-1]==nums[i])
                continue;
            if (index >= LIS.size())
                LIS.push_back(nums[i]);
            else
                LIS[index] = nums[i];
        }
        return LIS.size();
    }
};
