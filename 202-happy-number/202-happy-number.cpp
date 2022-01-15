class Solution {
public:
    bool isHappy(int n) {
        for(int i = 0; i < 100; i++)
        {
            if(n == 1) return true;
            int x = 0;
            while(n) {
                x += (n % 10) * (n % 10);
                n /= 10;
            }
            n = x;
        }
        
        return false;
    }
};