class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        for(int i = 0; i < s.length(); i++) {
            if(isalpha(s[i])) {
                ans += s[i];
                continue;
            }
            int num = 0;
            while(s[i] >= '0' && s[i] <= '9')
                num = num*10 + (s[i++] - '0');
            int open = 1, close = 0;
            string current = "";
            for(i = i + 1; i < s.length(); i++)
            {
                if(s[i] == '[')
                    open++;
                else if(s[i] == ']')
                    close++;
                
                if(open != close)
                    current += s[i];
                if(open == close)
                {
                    string temp = decodeString(current);
                    string offset = "";
                    for(int j = 0; j < num; j++)
                        offset += temp;
                    ans += offset;
                    break;
                }
            }
        }
        return ans;
    }
};
