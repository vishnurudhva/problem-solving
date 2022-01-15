class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < matrix.size(); i++)
            for(int j = i + 1; j < matrix[i].size(); j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};

/*
[[15,13,2,5],
 [14,4,8,1],
 [12,6,4,9],
 [16,7,10,11]]

[[15,13,2,5],
 [14,3,4,1],
 [12,6,8,9],
 [16,7,10,11]]
*/




