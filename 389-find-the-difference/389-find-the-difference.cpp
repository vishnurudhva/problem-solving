class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> map;
        for(char c: s)
            map[c]++;
        char result = '.';
        int count = s.length();
        for(char c: t) {
            if(map.find(c) != map.end() && map[c] != 0 && count != 0) {
                map[c]--;
                count--;
            } else
                result = c;
        }
        return result;
    }
};