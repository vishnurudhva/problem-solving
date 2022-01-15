class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = 0, c = 0, row = matrix.size() - 1, col = matrix[0].size() - 1;
        vector<int> result;
        while(r <= row && c <= col)
        {
            for(int i = c; i <= col; i++)
                result.push_back(matrix[r][i]);
            
            for(int i = r + 1; i <= row; i++)
                result.push_back(matrix[i][col]);
            
            for(int i = col - 1; i >= c; i--)
            {
                if(r != row)
                    result.push_back(matrix[row][i]);
            }
            
            for(int i = row - 1; i > r; i--)
            {
                if(c != col)
                    result.push_back(matrix[i][c]);
            }
            r++;
            c++;
            row--;
            col--;
        }
        
        return result;
    }
};