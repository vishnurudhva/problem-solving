class Solution {
public:    
    int numOfPairs(vector<string>& nums, string target) {
        vector<int> prefix(target.size(), 0), suffix(target.size(), 0);
        int result = 0;
        for(auto& num: nums) {
            if(num.length() < target.length()) {
                bool pref = target.compare(0, num.length(), num) == 0;
                bool suff = target.compare(target.length() - num.length(), num.length(), num) == 0;
                result += (pref ? suffix[num.length()] : 0) + (suff ? prefix[target.length() - num.length()] : 0);
                prefix[num.length()] += pref;
                suffix[target.length() - num.length()] += suff;
            }
        }
        return result;
    }
};