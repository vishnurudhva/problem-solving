class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;
        for(int i = 0; i < order.length(); i++)
        {
            map[order[i]] = i;
        }
        int i = 1, size = words.size();
        while(i < size)
        {
            string first = words[i - 1];
            string second = words[i];
            
            for(int j = 0; j < first.length(); j++)
            {
                if(j >= second.length() || map[first[j]] > map[second[j]]) {
                    return false;
                } else if (map[first[j]] < map[second[j]])
                    break;
            }
            
            i++;
        }
        
        return true;
    }
};