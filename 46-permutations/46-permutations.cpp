class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        generate(result, {}, nums);
        return result;
    }
    
    void generate(vector<vector<int>>& result, vector<int> temp, vector<int>& nums) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue;
            temp.push_back(nums[i]);
            generate(result, temp, nums);
            temp.pop_back();
        }
    }
};