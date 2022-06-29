class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_map<int, bool> map;
        sort(nums.begin(), nums.end());
        for (int num: nums)
            map[num] = false;
        generate(result, {}, nums, map);
        return result;
    }
    
    void generate(vector<vector<int>>& result, vector<int> temp, vector<int>& nums, unordered_map<int, bool>& map) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (map[i] || i > 0 && nums[i] == nums[i - 1] && !map[i - 1]) continue;
            map[i] = true;
            temp.push_back(nums[i]);
            generate(result, temp, nums, map);
            temp.pop_back();
            map[i] = false;
        }
    }
};