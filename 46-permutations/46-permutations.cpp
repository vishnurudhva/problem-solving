class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        generate(result, nums, 0);
        return result;
    }
    
    void generate(vector<vector<int>>& result, vector<int>& nums, int start) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            generate(result, nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
};