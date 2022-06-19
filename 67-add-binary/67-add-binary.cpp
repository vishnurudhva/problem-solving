class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        
        int i = a.length() - 1, j = b.length() - 1, s = 0;
        while (i >= 0 || j >= 0 || s == 1) {
            s += i >= 0 ? a[i] - '0': 0;
            s += j >= 0 ? b[j] - '0': 0;
            
            result = to_string(s % 2) + result;
            s = s / 2;
            i--;
            j--;
        }
        
        return result;
    }
};