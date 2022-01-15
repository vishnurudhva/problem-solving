class Solution {
public:
    int minimumBuckets(string street) {
        int result = 0;
        for(int i = 0; i < street.size(); i++) {
            if(street[i] == 'H') {
                if(i - 1 >= 0 && street[i - 1] == 'B') continue;
                if(i + 1 < street.size() && street[i + 1] == '.') {
                    result++;
                    street[i + 1] = 'B';
                    continue;
                }
                if(i - 1 >= 0 && street[i - 1] == '.') {
                    result++;
                    street[i - 1] = 'B';
                    continue;
                }
                return -1;
            }
        }
        return result;
    }
};