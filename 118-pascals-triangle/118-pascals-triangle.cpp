class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i = 0; i < numRows; i++) {
            result.push_back(vector<int>(i + 1));
            int c = result[i].size() - 1;
            result[i][0] = 1;
            result[i][c] = 1;
            if(i == 0) continue;
            int k = 0;
            for(int j = 1; j < c; j++, k++) {
                result[i][j] = result[i - 1][k] + result[i - 1][k + 1];
            }
        }
        
        return result;
    }
};