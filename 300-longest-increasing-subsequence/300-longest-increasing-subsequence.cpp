class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        auto end = nums.begin();
        for(int num: nums) {
            auto it = lower_bound(nums.begin(), end, num);
            *it = num;
            if(it == end)
                end++;
        }
        return end - nums.begin();
    }
};