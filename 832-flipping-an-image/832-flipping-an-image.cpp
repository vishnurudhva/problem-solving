class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i = 0; i < image.size(); i++)
        {
            int x = 0, y = image[i].size() - 1;
            while(x < y) {
                image[i][x] = 1 - image[i][x];
                image[i][y] = 1 - image[i][y];
                swap(image[i][x], image[i][y]);
                x++;
                y--;
            }
            if(x == y) image[i][x] = 1 - image[i][x];
        }
        
        return image;
    }
};