class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr(k, 0);
        int i = 0;
        
        while(i >= 0)
        {
            curr[i]++;
            if(curr[i] > n) --i;
            else if(i == k - 1) result.push_back(curr);
            else {
                i++;
                curr[i] = curr[i - 1];
            }
        }
        return result;
    }
};