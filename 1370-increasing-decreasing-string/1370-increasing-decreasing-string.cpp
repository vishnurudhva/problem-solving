class Solution {
public:
    string sortString(string s) {
        vector<int> bucket(26, 0);
        
        for(int i = 0; i < s.size(); i++)
            bucket[s[i] - 'a']++;
        
        string result;
        
        while(result.size() != s.size()) {
            for(int i = 0; i < bucket.size(); i++) {
                if(bucket[i] > 0 && bucket[i]--)
                    result += i + 'a';
            }
            
            for(int i = bucket.size() - 1; i >= 0; i--) {
                if(bucket[i] > 0 && bucket[i]--)
                     result += i + 'a';
            }
        }
        
        return result;
    }
};