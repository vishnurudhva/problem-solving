class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string key = "";
        int j = k;
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(iswalnum(s[i])) {
                if(j <= 0) {
                    key += "-";
                    j = k;
                }
                key += toupper(s[i]);
                j--;
            }
        }
        reverse(key.begin(), key.end());
        return key;
    }
};