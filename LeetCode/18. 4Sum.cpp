class Solution {
private:
    // Space complexity: O(1) (exclude solution)
    // Time complexity: O(N^3*log(N))
    // Runtime: 497 ms
    vector<vector<int>> fourSumBisect(vector<int>& nums, int target) {
        vector<vector<int>> solution;
        sort(nums.begin(), nums.end());
        // Let 0 <= a < b < c < d < n
        int prevA, prevB, prevC, prevD;
        for (int a=0; a<nums.size(); ++a) {
            if (a>0 && nums[a]==prevA)
                continue;
            prevA = nums[a];
            for (int b=a+1; b<nums.size(); ++b) {
                if (b>a+1 && nums[b]==prevB)
                    continue;
                prevB = nums[b];
                long long int ab = nums[a]+nums[b];
                // find ab + nums[c] + nums[d] = target (3-sum)
                // find nums[c] + nums[d] = target - ab
                // let D = target - ab
                // find nums[c] + nums[d] = D
                // iterate through nums[c]:
                //   find nums[d] = D - nums[c] by bisect
                long long int D = target - ab;
                for (int c=b+1; c<nums.size(); ++c) {
                    if (c>b+1 && nums[c]==prevC)
                        continue;
                    prevC = nums[c];
                    long long int val = D - nums[c];
                    auto it = lower_bound(nums.begin()+c+1, nums.end(), val);
                    if (it != nums.end() && *it == val) {
                        int d = (int)(it - nums.begin());
                        solution.push_back(vector<int>({nums[a],nums[b],nums[c],nums[d]}));
                    }
                }
            }
        }
        return solution;
    }
    // Space complexity: O(N)
    // Time complexity: O(N^3)
    // Runtime: 337 ms
    vector<vector<int>> fourSumHashmap(vector<int>& nums, int target) {
        vector<vector<int>> solution;
        unordered_map<int,int> query_num; // store value -> right-most index
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size(); ++i)
            query_num[nums[i]] = i;
        
        // Let 0 <= a < b < c < d < n
        int prevA, prevB, prevC, prevD;
        for (int a=0; a<nums.size(); ++a) {
            if (a>0 && nums[a]==prevA)
                continue;
            prevA = nums[a];
            for (int b=a+1; b<nums.size(); ++b) {
                if (b>a+1 && nums[b]==prevB)
                    continue;
                prevB = nums[b];
                long long int ab = nums[a]+nums[b];
                // find ab + nums[c] + nums[d] = target (3-sum)
                // find nums[c] + nums[d] = target - ab
                // let D = target - ab
                // find nums[c] + nums[d] = D
                // iterate through nums[c]:
                //   find nums[d] = D - nums[c] by bisect
                long long int D = target - ab;
                for (int c=b+1; c<nums.size(); ++c) {
                    if (c>b+1 && nums[c]==prevC)
                        continue;
                    prevC = nums[c];
                    long long int val = D - nums[c];
                    if (val>=INT_MIN && val <= INT_MAX && query_num.count(val)>0 && query_num[val]>c) {
                        solution.push_back(vector<int>({nums[a],nums[b],nums[c],(int)val}));
                    }
                }
            }
        }
        return solution;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return fourSumHashmap(nums, target);
    }
};
