class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        while(i >= 0 || j >= 0)
        {
            i = getNextIndex(s, i);
            j = getNextIndex(t, j);
            if(i < 0 || j < 0) return i < 0 && j < 0;
            if(s[i--] != t[j--]) return false;
        }
        return true;
    }
    
    int getNextIndex(string s, int i)
    {
        if(i < 0) return i;
        if(s[i] != '#') return i;
        
        int count = 0;
        while(i >= 0)
        {
            if(s[i] == '#')
            {
                count++;
                i--;
            }else if(count--)
                i--;
            else
                break;
        }
        return i;
    }
};