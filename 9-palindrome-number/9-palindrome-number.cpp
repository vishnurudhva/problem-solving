class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        long int g = 0;
        while(n > 0){
            g = (g*10) + n % 10;
            n /= 10;
        }
        return g == x;
    }
};