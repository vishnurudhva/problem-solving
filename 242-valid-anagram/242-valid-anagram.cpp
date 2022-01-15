class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for(int i = 0; i < s.length(); i++)
            map[s[i]]++;
        
        for(int i = 0; i < t.length(); i++)
        {
            map[t[i]]--;
            if(map[t[i]] < 0)
                return false;
        }
        
        for(int i = 0; i < s.length(); i++)
            if(map[s[i]] != 0) return false;
        
        return true;
    }
};