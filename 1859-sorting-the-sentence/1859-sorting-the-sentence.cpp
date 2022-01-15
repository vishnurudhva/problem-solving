class Solution {
public:
    string sortSentence(string s) {
        int cnt = count(s.begin(), s.end(), ' ') + 1;
        vector<string> sorted(cnt);
        string curr, curr_count;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ')
                if(s[i] >= '0' && s[i] <= '9')
                    curr_count += s[i];
                else 
                    curr += s[i];
            
            if(s[i] == ' ' || i == s.length() - 1) {
                int current = stoi(curr_count);
                sorted[current - 1] = curr;
                curr_count = "";
                curr = "";
            }
        }
        string result;
        for(int i = 0; i < sorted.size(); i++) {
            result += sorted[i];
            if(i != sorted.size() - 1)
                result += " ";
        }
        
        return result;
    }
};