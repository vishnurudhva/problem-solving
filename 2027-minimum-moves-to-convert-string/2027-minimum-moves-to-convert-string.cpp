class Solution {
public:
    int minimumMoves(string s) {
        int minMoves = 0;
        for(int i = 0; i < s.length(); i += s[i] == 'X' ? 3 : 1)
            minMoves += s[i] == 'X';
        return minMoves;
    }
};