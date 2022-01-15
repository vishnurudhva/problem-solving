class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        result.push_back(0);
        result.push_back(1);
        if(n == 0) return {0};
        int offset = 2;
        for(int i = 2; i <= n; i++)
        {
            if(i == offset*2)
                offset = i;
            result.push_back(result[i - offset] + 1); 
        }
        return result;
    }
};