class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int target = 0-nums[i];
                int x = i + 1, y = nums.size() - 1;
                while (x < y) {
                    if (nums[x] + nums[y] == target)
                    {
                        result.push_back({nums[i], nums[x++], nums[y]});
                        while (x < y && nums[x] == nums[x - 1]) x++;
                    } 
                    else if (nums[x] + nums[y] > target) y--;
                    else x++;
                }
            }
        }
        
        
        
        return result;
    }
};