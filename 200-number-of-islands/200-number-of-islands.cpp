class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numberOfIslands = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1'){
                    flood(grid, i, j);
                    numberOfIslands++;
                }
            }
        }
        return numberOfIslands;
    }
    
    void flood(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        flood(grid, i - 1, j);
        flood(grid, i + 1, j);
        flood(grid, i, j - 1);
        flood(grid, i, j + 1);
    }
};