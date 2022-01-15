class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        for(int num: nums)
        {
            int s = result.size();
            for(int j = 0; j < s; j++)
            {
                vector<int> ans = result[j];
                ans.push_back(num);
                result.push_back(ans);
            }
        }
        return result;
    }
};