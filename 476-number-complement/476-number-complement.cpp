class Solution {
public:
    int findComplement(int num) {
        int result = 0, k = 0;
        while(num) {
            if(num % 2 == 0)
                result += pow(2,k);
            num /= 2;
            k++;
        }
        return result;
    }
};