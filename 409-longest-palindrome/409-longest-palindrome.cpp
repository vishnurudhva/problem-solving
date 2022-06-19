class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for(char c: s) {
            map[c]++;
        }
        int longestLen = 0, offset = 0;
        for(auto m: map) {
            if(m.second % 2 == 1) offset = 1;
            longestLen += (m.second % 2 == 0 ? m.second: m.second - 1);
        }
        
        return longestLen + offset;
    }
};