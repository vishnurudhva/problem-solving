class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        generate(candidates, 0, {}, target, result);
        return result;
    }
    
    void generate(vector<int>& nums, int k, vector<int> curr, int target, vector<vector<int>>& result)
    {
        if(target == 0) {
            result.push_back(curr);
        }
        
        if(target < 0)
            return;
        
        for(int i = k; i < nums.size(); i++)
        {
            if(i > k && nums[i] == nums[i - 1]) continue;
            if(nums[i] > target) break;
            curr.push_back(nums[i]);
            generate(nums, i + 1, curr, target - nums[i], result);
            curr.pop_back();
        }
    }
};