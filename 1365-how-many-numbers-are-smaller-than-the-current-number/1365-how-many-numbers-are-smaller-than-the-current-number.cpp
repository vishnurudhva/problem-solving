class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> bucket(102, 0);
        for(int i: nums)
            bucket[i + 1]++;
        for(int i = 1; i < 102; i++)
            bucket[i] += bucket[i - 1];
        for(int i = 0; i < nums.size(); i++)
            nums[i] = bucket[nums[i]];
        return nums;
    }
};