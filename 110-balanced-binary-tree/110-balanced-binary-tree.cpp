class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool isBal = true;
        Balanced(root, isBal);
        return isBal;
    }
    
    int Balanced(TreeNode* root, bool& isBal) {
        if(root == NULL)
            return 0;
        int left = Balanced(root->left, isBal);
        int right = Balanced(root->right, isBal);
        if(abs(left - right) > 1)
            isBal = false;
        return 1 + max(left, right);
    }
};