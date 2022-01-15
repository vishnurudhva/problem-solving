class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> map;
        
        for(int i = 0; i < score.size(); i++)
        {
            map[score[i]] = i;
        }
        
        sort(score.begin(), score.end(), greater<int>());
        vector<string> result(score.size());
        string arr[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        int k = 0;
        string ans;
        for(int i = 0; i < score.size(); i++)
        {
            if(k >= 3)
                ans = to_string(k + 1);
            else
                ans = arr[k];
            
            result[map[score[i]]] = ans;
            k++;
        }
        
        return result;
    }
};