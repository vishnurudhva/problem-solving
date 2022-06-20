class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, length = 0;
        unordered_map<char, bool> map;
        int maxSize = 0;
        while(i < s.length() && j < s.length()) {
            if (map.find(s[j]) == map.end() || !map[s[j]]) {
                map[s[j++]] = true;
                maxSize++;
                length = max(length, maxSize);
                continue;
            }
            while (i < s.length() && s[j] != s[i]) {
                map[s[i]] = false;
                maxSize--;
                i++;
            }
            i++;
            j++;
        }
        
        return length;
    }
};