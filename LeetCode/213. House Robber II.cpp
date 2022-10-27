class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        if (nums.size()==2) return max(nums[0], nums[1]);
        int N = nums.size();
        vector<int> dp(3,0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for (int i=2; i<N-1; ++i) {
            dp[i%3] = max(dp[(i-1)%3], dp[(i-2)%3]+nums[i]);
        }
        int case1 = *max_element(dp.begin(), dp.end());
        
        dp[0] = nums[1];
        dp[1] = max(nums[1],nums[2]);
        for (int i=2; i<N-1; ++i) {
            dp[i%3] = max(dp[(i-1)%3], dp[(i-2)%3]+nums[i+1]);
        }
        int case2 = *max_element(dp.begin(), dp.end());
        return max(case1, case2);
    }
};
