class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (newColor == image[sr][sc]) return image;
        int oc = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            image[i][j] = newColor;
            if (i - 1 >= 0 && image[i - 1][j] == oc) q.push({i - 1, j});
            if (i + 1 < image.size() && image[i + 1][j] == oc) q.push({i + 1, j});
            if (j - 1 >= 0 && image[i][j - 1] == oc) q.push({i, j - 1});
            if (j + 1 < image[0].size() && image[i][j + 1] == oc) q.push({i, j + 1});
        }
        
        return image;
    }
};