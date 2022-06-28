class Solution {
public:
    
    void canBeRotten(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q, int& freshCount) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == 0 || grid[i][j] == 2)
            return;
        freshCount--;
        q.push({i, j});
        grid[i][j] = 2;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int freshCount = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) freshCount++;
            }
        }
        int result = -1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front(); q.pop();
                int r = p.first, c = p.second;
                canBeRotten(grid, r - 1, c, q, freshCount);
                canBeRotten(grid, r + 1, c, q, freshCount);
                canBeRotten(grid, r, c - 1, q, freshCount);
                canBeRotten(grid, r, c + 1, q, freshCount);
            }
            result++;
        }
        
        return freshCount ? -1 : result == -1 ? 0 : result;
    }
};