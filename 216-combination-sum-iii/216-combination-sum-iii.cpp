class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        generate(k, 1, {}, n, result);
        return result;
    }
    
    void generate(int k, int j, vector<int> curr, int target, vector<vector<int>>& result) { 
        if(curr.size() == k && target == 0)
        {
            result.push_back(curr);
            return;
        }
        
        if(target < 0) return;
        
        for(int i = j; i <= 9; i++)
        {
            curr.push_back(i);
            generate(k, i + 1, curr, target - i, result);
            curr.pop_back();
        }
    }
};