class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int mx = prices[prices.size() - 1], profit = 0;
        for(int i = prices.size() - 2; i >= 0; i--)
        {
            mx = max(prices[i], mx);
            profit = max(profit, mx - prices[i]);
        }
        return profit;
    }
};