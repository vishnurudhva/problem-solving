class Solution {
public:
    string reverseWords(string s) {
        string current = "", result = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ')
                current += s[i];
            if(current.length() == 0) continue;
            if(s[i] == ' ' || i == s.length() - 1) {
                result = current + (result.length() > 0 ? " " + result : "");
                current = "";
            }
        }
        return result;
    }
};