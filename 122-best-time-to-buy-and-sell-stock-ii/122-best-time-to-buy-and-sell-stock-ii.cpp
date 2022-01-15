class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size(), result = 0;
        int max_till = prices[size - 1];
        
        for(int i = size - 2; i >= 0; i--) {
            if(prices[i] < max_till)
                result += max_till - prices[i];
            max_till = prices[i];
        }
        
        return result;
    }
};