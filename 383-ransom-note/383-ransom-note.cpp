class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        int total_count = ransomNote.length();
        for(char c: ransomNote) {
            map[c]++;
        }
        
        for(char c: magazine) {
            if(map.find(c) != map.end() && map[c] != 0) {
                map[c]--;
                total_count--;
            }
        }
        
        
        return total_count == 0;
    }
};