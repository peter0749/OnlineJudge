class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        if (prices.size()<=1 || K<=0) return 0;
        size_t N = min(prices.size(),(size_t)K);
        vector<int> buy(N, INT_MAX);
        vector<int> sell(N, INT_MIN);
        sell[N-1] = 0;
        for (auto price : prices) {
            for (int k=0; k<N; ++k) {
                buy[k] = min(buy[k], k==0?price:price-sell[k-1]);
                sell[k] = max(sell[k], price-buy[k]);
            }
        }
        return sell[N-1];
    }
};
