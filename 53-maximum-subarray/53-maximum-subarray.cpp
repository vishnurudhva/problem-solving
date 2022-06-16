class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int maxTillNow = nums[0], maxOverall = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            maxTillNow = max(maxTillNow + nums[i], nums[i]);
            maxOverall = max(maxOverall, maxTillNow);
        }
        
        return maxOverall;
    }
};