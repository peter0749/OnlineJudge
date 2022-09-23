class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size();
        while (r-l>1) {
            int m = l + (r-l) / 2;
            if (nums[m] >= nums[0]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (l >= nums.size())
            return nums[0];
        if (l+1 < nums.size())
            return min(nums[l], nums[l+1]);
        return min(nums[0], nums[l]);
    }
};
