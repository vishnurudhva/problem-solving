class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        
        for(int i = 0; i < nums.size(); i++)
            map[nums[i]]++;
        
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto& num: map)
            bucket[num.second].push_back(num.first);
        
        vector<int> result;
        for(int i = bucket.size() - 1; i >= 0; i--){
            result.insert(result.end(), bucket[i].begin(), bucket[i].end());
            if(result.size() >= k) break;
        }
        
        return result;
    }
};