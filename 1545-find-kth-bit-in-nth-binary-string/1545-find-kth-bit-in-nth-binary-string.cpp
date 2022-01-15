class Solution {
public:
    string reverseInvert(string str) {
        string result = "";
        for(int i = str.length() - 1; i >= 0; i--)
            if(str[i] == '1')
                result += '0';
            else
                result += '1';
        return result;
    }
    
    char solve(int n, int k, int i, string current) {
        if(i == n)
            return current[k - 1];
        current += "1" + reverseInvert(current);
        return solve(n, k, i + 1, current);
    }
    
    char findKthBit(int n, int k) {
        return solve(n, k, 0, "0");
    }
};