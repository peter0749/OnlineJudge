class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        for (; i>=0; --i)
            if (nums[i]<nums[i+1])
                break;
        if (i<0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int j=nums.size()-1; j>=0; --j) {
            if (nums[i]<nums[j]) {
                swap(nums.at(i), nums.at(j));
                reverse(nums.begin()+i+1, nums.end());
                return;
            }
        }
    }
};
