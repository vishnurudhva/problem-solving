class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] == '0';
                    count++;
                    dissolveIsland(grid, i, j);
                }
            }
        }
        
        return count;
    }
    
    void dissolveIsland(vector<vector<char>>& grid, int i, int j) {
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while (!q.empty()) {
            pair<int, int> curr = q.front(); q.pop();
            
            for (int i = 0; i < 4; i++) {
                int r = curr.first + dir[i].first, c = curr.second + dir[i].second;
                
                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[r].size() && grid[r][c] == '1') {
                    grid[r][c] = '0';
                    q.push({r, c});
                }
            } 
        }
        
    }
};