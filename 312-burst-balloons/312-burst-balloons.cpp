class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<vector<int>> DP(n, vector<int>(n, 0));
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        for(int d = 1; d < n - 1; d++) {
            for(int i = 1; i < n - d; i++) {
                int j = i + d;
                int max_cost = INT_MIN;
                
                for(int k = i; k <= j - 1; k++) {
                    int q = DP[i][k] + DP[k + 1][j] + nums[i - 1] * nums[k] * nums[j];
                    max_cost = max(max_cost, q);
                }
                DP[i][j] = max_cost;
            }
        }
        return DP[1][n - 1];
    }
};