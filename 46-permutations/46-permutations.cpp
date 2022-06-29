class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_map<int, bool> map;
        for (int num: nums)
            map[num] = false;
        generate(result, {}, nums, map);
        return result;
    }
    
    void generate(vector<vector<int>>& result, vector<int> temp, vector<int>& nums, unordered_map<int, bool> map) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (map[i]) continue;
            map[i] = true;
            temp.push_back(nums[i]);
            generate(result, temp, nums, map);
            temp.pop_back();
            map[i] = false;
        }
    }
};