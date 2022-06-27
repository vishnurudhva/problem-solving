class Solution {
public:
    
    void downRight(vector<vector<int>>& grid, int i, int j, int rottenBy) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == 0 || grid[i][j] == 2)
            return;
        if (grid[i][j] < 0)
            if (rottenBy <= grid[i][j]) return;
        grid[i][j] = rottenBy;
        downRight(grid, i + 1, j, rottenBy - 1);
        downRight(grid, i, j + 1, rottenBy - 1);
        downRight(grid, i - 1, j, rottenBy - 1);
        downRight(grid, i, j - 1, rottenBy - 1);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    downRight(grid, i + 1, j, -1);
                    downRight(grid, i, j + 1, -1);
                    downRight(grid, i - 1, j, -1);
                    downRight(grid, i, j - 1, -1);
                }
            }
        }
        int result = INT_MAX;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) return -1;
                if (grid[i][j] < 0)
                    result = min(result, grid[i][j]);
            }
        }
        
        return result == INT_MAX ? 0 : -1 * result;
    }
};