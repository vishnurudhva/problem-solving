class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256, -1);
        
        int length = 0, start = -1;
        
        for(int i = 0; i < s.length(); i++) {
            if (map[s[i]] > start)
                start = map[s[i]];
            
            map[s[i]] = i;
            
            length = max(length, i - start);
        }
        
        return length;
    }
};