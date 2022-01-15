class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i: nums)
            map[i]++;
        vector<vector<int>> result;
        generate(map, {}, nums.size(), result);
        return result;
    }
    
    void generate(unordered_map<int, int>& map, vector<int> curr, int size, vector<vector<int>>& result)
    {
        if(curr.size() == size) {
            result.push_back(curr);
            return;
        }
        
        for(auto num: map)
        {
            if(num.second == 0) continue;
            
            curr.push_back(num.first);
            map[num.first]--;
            generate(map, curr, size, result);
            map[num.first]++;
            curr.pop_back();
        }
    }
};