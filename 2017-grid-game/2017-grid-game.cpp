class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top_sum = 0, bottom_sum = 0;
        int size = grid[0].size();
        for(int i = 0; i < size; i++)
            top_sum += grid[0][i];
        long long result = top_sum;
        for(int i = 0; i < size; i++)
        {
            top_sum -= grid[0][i];
            result = min(result, max(top_sum, bottom_sum));
            bottom_sum += grid[1][i];
        }
        return result;
    }
};