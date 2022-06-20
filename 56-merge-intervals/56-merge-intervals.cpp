class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result = {intervals[0]};
        
        for(int i = 1; i < intervals.size(); i++) {
            int last = result.size() - 1;
            if (result[last][1] >= intervals[i][0]) {
                result[last][1] = max(intervals[i][1], result[last][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        
        
        return result;
    }
};