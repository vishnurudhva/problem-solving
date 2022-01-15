class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        fill(image, sr, sc, newColor, image[sr][sc]);
        
        return image;
    }
    
    void fill(vector<vector<int>>& image, int sr, int sc, int newColor, int currentColor) {
        if(image[sr][sc] != currentColor) return;
        
        image[sr][sc] = newColor;
        
        if(sr + 1 < image.size()) fill(image, sr + 1, sc, newColor, currentColor);
        if(sr - 1 >= 0) fill(image, sr - 1, sc, newColor, currentColor);
        if(sc + 1 < image[0].size()) fill(image, sr, sc + 1, newColor, currentColor);
        if(sc - 1 >= 0) fill(image, sr, sc - 1, newColor, currentColor);
    }
};