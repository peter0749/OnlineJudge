// 0 ms, 100% faster solution
class Solution {
public:
    int rob(vector<int>& nums) {
        // 1 <= nums.length <= 100
        int N = nums.size();
        if (N == 1) return nums[0];
        nums[1] = max(nums[0], nums[1]);
        if (N == 2) return nums[1];
        
        // branch elimination in loop
        for (int i=2; i<N; ++i) {
            nums[i] = max(nums[i-1], nums[i-2]+nums[i]);
        }
        return nums[N-1];
    }
};
