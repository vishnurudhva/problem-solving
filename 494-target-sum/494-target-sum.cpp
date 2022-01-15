class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int result = 0;
        map<pair<int, int>, int> map;
        return calculate(nums, 0, 0, target, result, map);;
    }
    
    int calculate(vector<int>& nums, int k, int sum, int target, int& result, map<pair<int, int>, int>& map)
    {
        if(map.find({k, sum}) != map.end())
            return map[{k, sum}];
        if(k == nums.size() && target == sum) return 1;
        if(k == nums.size()) return 0;
        
        int pos = calculate(nums, k + 1, sum + nums[k], target, result, map);
        int neg = calculate(nums, k + 1, sum - nums[k], target, result, map);
        map[{k, sum}] = pos + neg;
        return pos + neg;
    }
    
};