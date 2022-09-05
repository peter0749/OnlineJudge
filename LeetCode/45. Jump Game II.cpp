class Solution {
public:
    int jump(vector<int>& nums) {
        // No backward jumping since current position is 
        // already reachable from some position on its left
        // No backward jumping => nums is a DAG
        // Find shortest path from 0 to N-1 in DAG
        if (nums.size() <= 1) return 0;
        
        int N = nums.size();
        vector<int> dp(N, INT_MAX);
        dp[0] = 0;
        int i=0;
        while(i<N) {
            int best_next = i+1;
            int best = 0;
            for (int j=i+1; j<N && j<=i+nums[i]; ++j) {
                dp[j] = min(dp[j], dp[i]+1);
                // Greedy strategy here
                // upper bound cost at j is dp[i]+1
                // Find next position with rightest reachable index
                if (j+nums[j]>best) {
                    best = j+nums[j];
                    best_next = j;
                }
            }
            i = best_next;
        }
        
        return dp[N-1];
    }
};
