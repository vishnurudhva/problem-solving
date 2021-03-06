class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int output = 0;
        for(int k = 2; k < nums.size(); k++)
        {
            int i = 0, j = k - 1;
            
            while(i < j)
                if(nums[i] + nums[j] > nums[k]){
                    output += j - i;
                    j--;
                }
                else
                    i++;
        }
        
        return output;
    }
};