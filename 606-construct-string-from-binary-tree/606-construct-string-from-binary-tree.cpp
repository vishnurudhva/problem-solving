class Solution {
public:
    void solve(TreeNode* root , string& s)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL) {
            s += to_string(root->val);
            return;
        }
        s += to_string(root->val);
        if(root->left) {
            s += '(';
            solve(root->left, s);
            s += ')';
        }
        
        if(root->right) {
            if(root->left == NULL)
                s += "()";
            s += '(';
            solve(root->right, s);
            s += ')';
        }
    }
    
    string tree2str(TreeNode* root) {
        string res = "";
        solve(root, res);
        return res;
    }
};