class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0, size = (rolls.size() + n);
        for(int r: rolls)
            sum += r;
        
        int what = size * mean - sum;
        if(n*6 < what || what < n) return {};
        
        int offset = what / n;
        what -= n * offset;
        
        
        vector<int> result;
        for(int i = 0; i < n; i++) {
            int ans = offset + (what > 0);
            result.push_back(ans);
            what--;
        }
        return result;
    }
};