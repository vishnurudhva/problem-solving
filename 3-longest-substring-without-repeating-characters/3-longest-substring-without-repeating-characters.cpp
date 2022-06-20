class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int i = 0, j = 0, length = 1;
        unordered_set<char> st;
        while(i < s.length() && j < s.length()) {
            if (st.find(s[j]) == st.end()) {
                st.insert(s[j++]);
                length = max(length, (int) st.size());
                continue;
            }
            while (i < s.length() && s[j] != s[i]) {
                st.erase(s[i]);
                i++;
            }
            i++;
            j++;
        }
        
        return length;
    }
};