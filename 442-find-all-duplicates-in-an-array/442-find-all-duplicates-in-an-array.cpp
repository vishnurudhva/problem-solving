class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        {
            swap(nums[i], nums[nums[i] - 1]);
            if(nums[i] != nums[nums[i] - 1]) i--;
        }
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] - 1 != i) result.push_back(nums[i]);
        return result;
    }
};
