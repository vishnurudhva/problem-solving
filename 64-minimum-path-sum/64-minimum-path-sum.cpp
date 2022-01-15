class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> DP(grid.size(), vector<int>(grid[0].size(), -1));
        return get(grid, DP, 0, 0);
    }
    
    int get(vector<vector<int>>& grid, vector<vector<int>> &DP, int i, int j) {
        if(i >= grid.size() || j >= grid[i].size()) return 0;
        
        if(DP[i][j] != -1) return DP[i][j];
        
        
        int down = -1, right = -1, min_path = 0;
        if(i + 1 < grid.size())
            down = get(grid, DP, i + 1, j);
        if(j + 1 < grid[0].size())
            right = get(grid, DP, i, j + 1);
        if(down != -1 && right != -1)
            min_path = min(down, right);
        else if(down == -1 && right == -1)
            min_path = 0;
        else min_path = down + right + 1;
        
        DP[i][j] = grid[i][j] + min_path;
        
        return DP[i][j];
    }
};