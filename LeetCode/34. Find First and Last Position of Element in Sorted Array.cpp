class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> sol;
        int l=0, r=nums.size();
        
        if (r == 0) {
            sol.push_back(-1); sol.push_back(-1);
            return sol;
        }
        
        while(l+1<r) {
            int m = l + (r-l) / 2;
            if (nums[m] < target) {
                l = m;
            } else {
                r = m;
            }
        }
        if (nums[l] == target) {
            sol.push_back(l);
        } else {
            ++l;
            if (l >= nums.size() || nums[l] != target) {
                sol.push_back(-1); sol.push_back(-1);
                return sol;
            }
            sol.push_back(l);
        }
        r = nums.size();
        while (l+1<r) {
            int m = l + (r-l) / 2;
            if (nums[m] <= target) {
                l = m;
            } else {
                r = m;
            }
        }
        sol.push_back(l);
        return sol;
    }
};
