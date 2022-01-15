class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        getsubsets(result, {}, nums, 0);
        return result;
    }
    
    void getsubsets(vector<vector<int>> &result, vector<int> list, vector<int> nums, int start)
    {
        result.push_back(list);
        for(int i = start; i < nums.size(); i++)
        {
            if(i > start && nums[i] == nums[i - 1]) continue;
            list.push_back(nums[i]);
            getsubsets(result, list, nums, i + 1);
            list.pop_back();
        }
    }
};