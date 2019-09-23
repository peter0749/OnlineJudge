class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int max_profit=0;
        vector<int> left, right;
        for (int i=1; i<prices.size(); ++i) {
            profit = max(0, profit+prices[i]-prices[i-1]);
            max_profit = max(max_profit, profit);
            left.push_back(max_profit);
        }
        profit=0;
        max_profit=0;
        for (int i=prices.size()-1; i>=1; --i) {
            profit = max(0, profit+prices[i]-prices[i-1]);
            max_profit = max(max_profit, profit);
            right.push_back(max_profit);
        }
        max_profit = 0;
        for (int i=0; i<left.size(); ++i) {
            profit = left[i];
            int left_len = i+2;
            int right_len = prices.size()-left_len;
            if (right_len>=2 && right_len-2<right.size()) {
                profit += right[right_len-2];
            }
            max_profit = max(max_profit, profit);
        }
        return max_profit;
    }
};
