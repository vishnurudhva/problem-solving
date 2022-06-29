class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        generate(candidates, target, result, {}, 0);
        return result;
    }
    
    void generate(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int> temp, int i) {
        if (0 == target) {
            result.push_back(temp);
            return;
        }
        if (i >= candidates.size() || target < 0) return;
        
        temp.push_back(candidates[i]);
        generate(candidates, target - candidates[i], result, temp, i);
        temp.pop_back();
        generate(candidates, target, result, temp, i + 1);
    }
};