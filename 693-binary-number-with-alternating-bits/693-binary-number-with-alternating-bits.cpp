class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n % 2;
        n /= 2;
        while(n) {
            if(n % 2 != prev)
              prev = n % 2;
            else
                return false;                
            n /= 2;
        }  
        return true;
    }
};