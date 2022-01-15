class Solution {
public:
    bool isValid(string s) {
        map<char, char> brackets = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        stack<char> stk;
        for(int i = 0; i < s.length(); i++)
            if(brackets.find(s[i]) != brackets.end())
                stk.push(s[i]);
            else
                if(!stk.empty() && s[i] == brackets[stk.top()])
                    stk.pop();
                else
                    return false;
        return stk.empty();
    }
};