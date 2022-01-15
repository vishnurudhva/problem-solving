class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char result = ' ';
        for(int i = 0; i < letters.size(); i++)
        {
            if(letters[i] > target)
            {
                result = letters[i];
                break;
            }
            
            if(i == letters.size() - 1)
                return letters[0];
        }
        return result;
    }
};