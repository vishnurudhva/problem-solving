class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        
        for(int i = 0; i < columnTitle.length(); i++)
        {
            char C = columnTitle[i];
            result = (result * 26) + (C - 'A' + 1);
        }
        return result;
    }
};