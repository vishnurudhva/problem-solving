class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = *max_element(nums.begin(), nums.end()), i = 0, actSum = 0;
        while(i < nums.size() && nums[i] < 0) i++;
        if(i == nums.size()) return maxSum;
        maxSum = 0;
        for(; i < nums.size(); i++)
        {
            actSum += nums[i];
            maxSum = max(actSum, maxSum);
            if(actSum < 0)
                actSum = 0;                
        }
        return maxSum;
    }
};