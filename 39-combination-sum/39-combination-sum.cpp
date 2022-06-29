class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        generate(candidates, target, result, 0, {}, 0);
        return result;
    }
    
    void generate(vector<int>& candidates, int& target, vector<vector<int>>& result, int currentSum, vector<int> temp, int i) {
        if (currentSum == target) {
            result.push_back(temp);
            return;
        }
        if (i >= candidates.size() || currentSum > target) return;
        
        temp.push_back(candidates[i]);
        generate(candidates, target, result, currentSum + candidates[i], temp, i);
        temp.pop_back();
        generate(candidates, target, result, currentSum, temp, i + 1);
    }
};