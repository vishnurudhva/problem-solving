class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool verticalPaint = false;
        
        int rowSize = matrix.size(), colSize = matrix[0].size();
        
        for(int i = 0; i < rowSize; i++) {
            if(matrix[i][0] == 0) verticalPaint = true;
            for(int j = 1; j < colSize; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = rowSize - 1; i >= 0; i--) {
            for(int j = 1; j < colSize; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
            if(verticalPaint)
                matrix[i][0] = 0;
        }
    }
};