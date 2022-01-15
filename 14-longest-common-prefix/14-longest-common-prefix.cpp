class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        for(int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            for(int j = 0; j < strs.size(); j++)
                if(i >= strs[j].length() || strs[j][i] != c)
                    return result;
            result += c;
        }
        return result;
    }
};