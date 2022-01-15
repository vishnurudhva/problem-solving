class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        generate(s, result, 0, current);
        return result;
    }
    
    void generate(string s, vector<vector<string>> &result, int k, vector<string>& current)
    {
        if(k == s.length())
        {
            result.push_back(current);
            return;
        }
        
        for(int i = k; i < s.length(); i++)
        {
            string temp = s.substr(k, i - k + 1);
            if(isPalindrome(temp)) {
                current.push_back(temp);
                generate(s, result, i + 1, current);
                current.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s)
    {
        if(s.length() == 1) return true;
        for(int i = 0; i < s.length(); i++)
            if(s[i] != s[s.length() - 1 - i])
                return false;
        return true;
    }
};