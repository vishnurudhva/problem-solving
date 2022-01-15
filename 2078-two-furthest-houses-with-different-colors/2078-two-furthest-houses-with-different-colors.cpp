class Solution {
public:
    int maxDistance(vector<int>& cs) {
        int p = INT_MAX, res = 1;
        for (int i = 1; i < cs.size(); ++i) {
            if (cs[i] != cs[0])
                p = min(i, p);
            res = max({res, cs[i] == cs[0] ? 0 : i, i - p });
        }
        return res;
    }
};