class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> DP(amount + 1, amount + 1);
        DP[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i] <= j)
                    DP[j] = min(DP[j], DP[j - coins[i]] + 1);
            }
        }
        
        return DP[amount] > amount ? - 1 : DP[amount];
    }
};