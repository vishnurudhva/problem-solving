class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> map1;
        for(string s: words1)
            map1[s]++;
        unordered_map<string, int> map2;
        for(string s: words2)
            map2[s]++;
        int result = 0;
        for(auto& node: map1) {
            if(node.second == 1 && map2.find(node.first) != map2.end() && map2[node.first] == 1)
                result++;
        }
        return result;
    }
};