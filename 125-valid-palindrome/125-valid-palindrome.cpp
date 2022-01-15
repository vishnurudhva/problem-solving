class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j) {
            while(i < s.length() && !iswalnum(s[i])) i++;
            while(j >= 0 && !iswalnum(s[j])) j--;
            if(i > j || i >= s.length() || j < 0) return true;
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        
        return true;
    }
};