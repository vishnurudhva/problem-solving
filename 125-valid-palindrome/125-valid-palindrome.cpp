class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        
        while (i < j) {
            while (i < s.length() && !isalnum(s[i])) i++;
            while (j >= 0 && !isalnum(s[j])) j--;
            
            if(i > j) break;
            
            if(tolower(s[i++]) != tolower(s[j--])) return false;
        }
        
        return true;
    }
};