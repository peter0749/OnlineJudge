class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int max_profit=0;
        for (int i=1; i<prices.size(); ++i) {
            profit = max(0, profit+prices[i]-prices[i-1]);
            max_profit = max(profit, max_profit);
        }
        return max_profit;
    }
};
