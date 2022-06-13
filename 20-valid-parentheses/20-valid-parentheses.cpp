class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> m;
        m['{'] = '}';
        m['['] = ']';
        m['('] = ')';
        for (char c: s) {
            if (m.find(c) != m.end())
                stk.push(c);
            else {
                if (!stk.empty() && m[stk.top()] == c) 
                    stk.pop();
                else
                    return false;
            }
                
        }
        
        return stk.empty();
    }
};