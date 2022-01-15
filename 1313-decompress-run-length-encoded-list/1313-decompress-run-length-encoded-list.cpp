class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int i = 0, size = nums.size();
        vector<int> result;
        while(2*i + 1 < size) {
            for(int j = 0; j < nums[2*i]; j++)
                result.push_back(nums[2*i + 1]);
            i++;
        }
        return result;
    }
};