class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return size;
        int prev = 1, curr = 1;
        for(int i = 0; i < size - 1; i++)
        {
            if(nums[i+1] == nums[i])
                continue;
            else
                nums[prev++] = nums[i+1];
        }
        return prev;
    }
};