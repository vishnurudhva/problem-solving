class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j) {
            if(s[i] != s[j])
                return isPalindrome(s.substr(i, j - i)) || isPalindrome(s.substr(i + 1, j - i));
            i++;
            j--;
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j)
            if(s[i++] != s[j--]) return false;
        return true;
    }
};

