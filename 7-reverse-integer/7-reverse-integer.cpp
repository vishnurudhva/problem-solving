class Solution {
public:
    int reverse(int x) {
        bool sign = x < 0;
        x = abs(x);
        int n = 0, count = 0;
        while(x > 0)
        {
            if(count == 9 && !(n > 214748364) && n*10 > 2147483640)
            {
                if(sign && x % 10 > 8) return 0;
                else if(!sign && x % 10 > 7) return 0;
            }
            if(n > 214748364) return 0;
            n = (n * 10) + (x % 10);
            count++;
            x = x/10;
        }
        return sign ? -1 * n : n;   
    }
};