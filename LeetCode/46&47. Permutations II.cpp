class Solution {
    inline bool next_permute(vector<int>& nums) {
        if (nums.size()<=1) return false;
        int break_point = nums.size()-2;
        for (; break_point>=0 && nums[break_point]>=nums[break_point+1]; --break_point);
        if (break_point<0) {
            reverse(nums.begin(), nums.end());
            return false;
        }
        int index_max = nums.size()-1;
        for (; nums[index_max]<=nums[break_point]; --index_max);
        swap(nums.at(index_max), nums.at(break_point));
        reverse(nums.begin()+break_point+1, nums.end());
        return true;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> solution;
        if (nums.size() == 0) return solution;
        sort(nums.begin(), nums.end());
        solution.push_back(nums);
        while(next_permute(nums)) solution.push_back(nums);
        return solution;
    }
};
