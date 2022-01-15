class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        generate(nums, 0, result);
        return result;
    }
    
    void generate(vector<int>& nums, int k, vector<vector<int>>& result) {
        
        if(k == nums.size())
            result.push_back(nums);
        else
        for(int i = k; i < nums.size(); i++)
        {
            swap(nums[k], nums[i]);
            generate(nums, k + 1, result);
            swap(nums[k], nums[i]);
        }
    }
};