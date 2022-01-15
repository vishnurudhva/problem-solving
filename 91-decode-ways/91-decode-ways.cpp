class Solution {
public:
    int numDecodings(string A) {
        vector<int> DP(A.size() + 1, 0);
        DP[0] = 1;
        DP[1] = (A[0] != '0');

        for(int i = 2; i <= A.length(); i++) {
            int one = stoi(A.substr(i - 1, 1));
            int two = stoi(A.substr(i - 2, 2));

            if(one > 0) DP[i] += DP[i - 1];
            if(two > 9 && two < 27) DP[i] += DP[i - 2];
        }
        return DP[A.size()];
    }
};