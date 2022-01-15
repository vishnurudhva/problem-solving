class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int size = digits.size();
        int carry = 1;
        for(int i = size - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
            if(sum <= 9) return digits;
        }
        
        if(carry != 0)
            digits.insert(digits.begin(), carry);
        
        
        return digits;
    }
};