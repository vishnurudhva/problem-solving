class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 1, start = 0, size = s.length();
        for (int i = 0; i < size; i++) {
            int len = 0;
            if (i > 0 && s[i] == s[i - 1])
                len = getPalLength(s, i - 1, i);
            if (i > 0 && i + 1 < size && s[i - 1] == s[i + 1])
                len = max(len, getPalLength(s, i - 1, i + 1) + 1);
            if (len > maxLen) {
                maxLen = len;
                start = i - maxLen/2;
            }
        }
        return s.substr(start, maxLen);
    }
    
    int getPalLength(string s, int i, int j) {
        int count = 0;
        while (i >= 0 && j < s.size()) {
            if (s[i] != s[j]) break;
            count += 2;
            i--;
            j++;
        }
        return count;
    }
};