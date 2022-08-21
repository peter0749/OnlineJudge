class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Don't need to jump backward since current position
        // is already reachable. nums[] is just a DAG!
        vector<bool> reachable(nums.size(), false);
        reachable[0] = true;
        int N = nums.size();
        int i=0;
        while (i<N && reachable[i] && !reachable[N-1]) {
            int next_i = i+1;
            int best_jump = -1;
            for (int j=i+1; j<N && j<=i+nums[i] && !reachable[N-1]; ++j) {
                reachable[j] = true;
                int jump_val = min(N-1, j+nums[j]);
                if (jump_val >= best_jump) {
                    best_jump = jump_val;
                    next_i = j;
                }
            }
            i = next_i;
        }
        return reachable[N-1];
    }
};
