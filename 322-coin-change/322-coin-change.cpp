class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> DP(amount + 1, 0);
        int ans = calculateChange(coins, amount, DP);
        return ans;
    }
    
    int calculateChange(vector<int>& coins, int amount, vector<int>& DP) {
        if (amount < 0) return -1;
        
        if (amount == 0) return 0;
        
        if (DP[amount] != 0) return DP[amount];
        int minValue = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int value = calculateChange(coins, amount - coins[i], DP);
            
            if (value != -1)
                minValue = min(minValue, 1 + value);
        }
        
        DP[amount] = minValue == INT_MAX ? -1 : minValue;
        return DP[amount];
    }
};