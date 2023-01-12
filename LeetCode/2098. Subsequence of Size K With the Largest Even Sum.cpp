class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        vector<long long> oddNums, evenNums;
        for (auto v : nums) {
            if (v & 1)
                oddNums.push_back(v);
            else
                evenNums.push_back(v);
        }
        sort(oddNums.begin(), oddNums.end(), greater<int>());
        sort(evenNums.begin(), evenNums.end(), greater<int>());
        partial_sum(oddNums.begin(), oddNums.end(), oddNums.begin());
        partial_sum(evenNums.begin(), evenNums.end(), evenNums.begin());
        long long maxVal = -1;
        size_t nMaxChooseOdd = min((size_t)k, oddNums.size());
        for (int nChooseOdd=0; nChooseOdd<=nMaxChooseOdd; nChooseOdd += 2) {
            int nChooseEven = k - nChooseOdd;
            if (nChooseEven > evenNums.size())
                continue;
            long long oddSum = nChooseOdd?oddNums[nChooseOdd-1]:0;
            long long evenSum = nChooseEven?evenNums[nChooseEven-1]:0;
            maxVal = max(maxVal, oddSum+evenSum);
        }
        return maxVal;
    }
};
