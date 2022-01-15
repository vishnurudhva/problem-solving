class Solution {
public:
    string reverseWords(string s) {
        int j = -1;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ' && j == -1)
                j = i;
            
            if((s[i] == ' ' && j != -1) || (i == s.length() - 1)) {
                if(i == s.length() - 1) i++;
                reverse(s.begin() + j, s.begin() + i);
                j = -1;
            }
        }
        
        return s;
    }
};