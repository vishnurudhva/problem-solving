class Solution {
public:
    bool isvowel(char c) {
        char arr[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i = 0; i < 10; i++)
            if(c == arr[i])
                return true;
        
        return false;
    }
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j)
        {
            while(i < s.length() && !isvowel(s[i])) i++;
            while(j >= 0 && !isvowel(s[j])) j--;
            if(i >= j) break;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};