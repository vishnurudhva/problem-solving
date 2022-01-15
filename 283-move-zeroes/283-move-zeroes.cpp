class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int startZero = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0)
                swap(nums[startZero++], nums[i]);
        }
        
        for(int i = startZero; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};