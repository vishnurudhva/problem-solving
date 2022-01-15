class Solution {
public:
    string removeOuterParentheses(string S) {
        
    int i=1, n=S.length(),c=0, j=0;
    char arr[S.length()];
    while(i<n){
        if(S[i]=='(') c++;
        if(S[i]==')') c--;
        if(c>=0){
            cout<<S[i];
            arr[j++]=S[i];
            i++;
            continue;
        }else{
            c=0;
            i+=2;
            continue;
        }
    }
        arr[j]='\0';
        return arr;
    }
};