class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        generate(candidates, {}, 0, target, result);
        return result;
    }
    
    void generate(vector<int>& nums, vector<int> curr, int k, int target, vector<vector<int>>& result) {
        if(0 == target) 
        {
            result.push_back(curr);
            return;
        }
        
        if(target < 0)
            return;
        
        for(int i = k; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            generate(nums, curr, i, target - nums[i], result);
            curr.pop_back();
        }
    
    }
};