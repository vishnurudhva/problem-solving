// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l = 0, r = n, m;
        while(l <= r)
        {
            m = (l + r) / 2;
            if(isBadVersion(m) == false && isBadVersion(m + 1) == true)
                return m + 1;
            else if(isBadVersion(m) == true)
                r = m - 1;
            else
                l = m + 1;
        }
        return m + 1;
    }
};