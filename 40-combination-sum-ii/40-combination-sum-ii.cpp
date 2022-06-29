class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        unordered_map<int, bool> map;
        for (int can: candidates)
            map[can] = false;
        sort(candidates.begin(), candidates.end());
        generate(candidates, target, result, {}, 0, map);
        return result;
    }
    
    void generate(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int> temp, int i, unordered_map<int, bool>& map) {
        if (0 == target) {
            result.push_back(temp);
            return;
        }
        if (i >= candidates.size() || target < 0) return;
        
        for (int j = i; j < candidates.size(); j++) {
            if (map[j] || j > 0 && candidates[j] == candidates[j - 1] && !map[j - 1]) continue;
            map[j] = true;
            temp.push_back(candidates[j]);
            generate(candidates, target - candidates[j], result, temp, j + 1, map);
            temp.pop_back();
            map[j] = false;
        }
    }
};