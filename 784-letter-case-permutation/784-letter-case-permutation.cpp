class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        result.push_back(s);
        getPermutation(s, result, 0);
        
        return result;
    }
    
    void getPermutation(string &s, vector<string>& result, int ind)
    {
        if(ind >= s.length()) return;
        if(!isalpha(s[ind])){
            getPermutation(s, result, ind + 1);
            return;
        }
        s[ind] = isupper(s[ind]) ? tolower(s[ind]) : toupper(s[ind]);
        result.push_back(s);
        getPermutation(s, result, ind + 1);

        s[ind] = isupper(s[ind]) ? tolower(s[ind]) : toupper(s[ind]);        
        getPermutation(s, result, ind + 1);
    }
};