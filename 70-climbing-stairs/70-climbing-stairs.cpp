class Solution {
public:
    int climbStairs(int n) {
        int b = 0, c = 1;
        while (n--) {
            int t = c;
            c += b;
            b = t;
        }
        return c;
    }
};