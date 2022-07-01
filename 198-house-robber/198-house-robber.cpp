class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];
        if (size > 2) nums[2] += nums[0];
        for (int i = 3; i < size; i++) {
            nums[i] += max(nums[i - 2], nums[i - 3]);
        }
        
        return max(nums[size - 1], nums[size - 2]);
    }
};