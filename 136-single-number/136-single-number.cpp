class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            x ^= nums[i];
            cout << x << endl;
        }
            
        return x;
    }
};