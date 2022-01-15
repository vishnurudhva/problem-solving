class Solution {
    unordered_map<char, string> map = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
                                           {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                           {'8', "tuv"}, {'9', "wxyz"}};
public:
    void backtrack(vector<string> &result, string comb, string n)
    {
        if(n == "")
        {
            result.push_back(comb);
            return;
        }


        for(int j = 0; j < map[n[0]].length(); j++)
            backtrack(result, comb + map[n[0]][j], n.substr(1, n.length() - 1));

    }
    vector<string> letterCombinations(string digits) {
        vector<string> result = {};
        
        if(digits != "") 
            backtrack(result, "", digits);
        
        return result;
    }
};