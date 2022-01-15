class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.size() == 0) return {};
        vector<int> result;
        int i;
        for(i = 0; i < nums.size(); i++)
            if(nums[i] >= 0)
                break;
        int x = i - 1, y = i;
        while(x >= 0 && y < nums.size())
        {
            if(nums[x]*nums[x] > nums[y]*nums[y])
                result.push_back(nums[y] * nums[y++]);
            else 
                result.push_back(nums[x] * nums[x--]);
        }
        
        while(x >= 0) result.push_back(nums[x] * nums[x--]);
        while(y < nums.size()) result.push_back(nums[y] * nums[y++]);
        return result;
    }
};