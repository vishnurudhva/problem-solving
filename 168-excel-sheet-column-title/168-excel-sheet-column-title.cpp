class Solution {
public:
    string convertToTitle(int n) {
        string s;
        char temp;
        while(n)
        {
            n -= 1;
            temp = 'A' + n % 26;
            s = temp + s;
            n /= 26;
        }
        
        return s;
    }
};