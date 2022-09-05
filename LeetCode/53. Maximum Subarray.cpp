class Solution {
public:
    // Time complexity: O(n)
    // Using partial sum + DP
    // Runtime: 160 ms
    inline int query(const vector<int>& nums, int left, int right) {
        // In python: nums[left:right-1].sum()
        // {0}, {0,1}, {0,1,2}, {0,1,2,3}
        if (left>0)
            return nums[right] - nums[left-1];
        return nums[right];
    }
    int maxSubArray(vector<int>& nums) {
        // [8, -19, 5, -4 , 20]
        // extend: 8(0), -11(0), -6(0),  1(2), 21(2)
        // newseg: 8(0), -19(1),  5(2), -4(3), 20(4)
        partial_sum(nums.begin(), nums.end(), nums.begin());
        int N = nums.size();
        int max_num = nums[0];
        vector<int> track(N, 0); // store left boundary
        for (int i=1; i<nums.size(); ++i) {
            int from_extend = query(nums, track[i-1], i);
            int from_newseg = query(nums, i-1, i);
            int newseg = query(nums, i, i);
            if (from_extend > from_newseg) {
                track[i] = track[i-1];
            } else {
                track[i] = i-1;
            }
            max_num = max({max_num, from_extend, from_newseg, newseg});
        }
        return max_num;
    }
};
