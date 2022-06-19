class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int x = i >= 0 ? a[i] - '0': 0;
            int y = j >= 0 ? b[j] - '0': 0;
            
            result = to_string((x + y + carry) % 2) + result;
            carry = (x + y + carry) / 2;
            i--;
            j--;
        }
        
        return carry ? "1" + result: result;
    }
};