class Solution {
public:
    int mySqrt(int x) {
        long l = 0, r = x;
        while(l < r)
        {
            long m = (l + r + 1) / 2;
            if (m*m > x) r = m - 1;
            else l = m;
        }
        return r;
    }
};