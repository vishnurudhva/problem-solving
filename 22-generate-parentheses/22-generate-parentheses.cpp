class Solution {
public:
    void backtrack(vector<string> &result, string comb, int k, int n, int open, int close)
    {
        if(k == n*2)
        {
            result.push_back(comb);
            return;
        }
        
        if(open > 0)
            backtrack(result, comb + '(', k + 1, n, open - 1, close + 1);
        
        if(close > 0)
            backtrack(result, comb + ')', k + 1, n, open, close - 1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, n, n, 0);
        return result;
    }
};