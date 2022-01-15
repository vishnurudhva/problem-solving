class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string str = "";
        string max_occurence = "";
        unordered_map<string, int> map;
        map[max_occurence] = 0;
        for(int i = 0; i < paragraph.size(); i++)
        {
            if(isalpha(paragraph[i]))
                str += paragraph[i];
            else{
                transform(str.begin(), str.end(), str.begin(), ::tolower);
                if(find(banned.begin(), banned.end(), str) == banned.end()){
                    map[str]++;
                    if(map[max_occurence] < map[str])
                        max_occurence = str;
                }
                str = "";
                while(i < paragraph.size() && !isalpha(paragraph[i])) i++;
                i--;
            }

        }

        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if(find(banned.begin(), banned.end(), str) == banned.end()) {
            map[str]++;
            if(map[max_occurence] < map[str])
                max_occurence = str;
        }
        return max_occurence;
    }
};