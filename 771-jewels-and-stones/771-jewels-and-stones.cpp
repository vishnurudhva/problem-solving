class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int total = 0;
        unordered_set<char> set(J.begin(), J.end());
        for(char c: S)
            if(set.count(c))
                total++;
        return total;
    }
};