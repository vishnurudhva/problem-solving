class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for(char c: s) {
            map[c]++;
        }
        int offset = 0;
        for(auto m: map) {
            offset += m.second % 2;
        }
        
        return s.size() - offset + (offset > 0);
    }
};