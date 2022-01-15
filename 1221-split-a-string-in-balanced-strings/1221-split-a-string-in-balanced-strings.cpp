class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0, l = 0, r = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'R') r++;
            else l++;
            
            if(l == r) {
                l = 0;
                r = 0;
                count++;
            }
        }
        return count;
    }
};