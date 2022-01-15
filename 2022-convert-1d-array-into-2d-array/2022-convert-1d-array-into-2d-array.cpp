class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n) return {};
        vector<vector<int>> result(m, vector<int>(n));
        int x = 0, y = 0;
        for(int i = 0; i < original.size(); i++)
        {
            if(y == n) {
                x++;
                y = 0;
            }
            result[x][y++] = original[i];
        }
        
        return result;
    }
};