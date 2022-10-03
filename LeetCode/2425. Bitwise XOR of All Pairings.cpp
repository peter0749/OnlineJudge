class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int s = 0;
        if (nums2.size()&1)
            for (auto v : nums1)
                s ^= v;
        if (nums1.size()&1)
            for (auto v : nums2)
                s ^= v;
        return s;
    }
};
