/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* result = NULL) {
        if (root == NULL) return result;
        TreeNode* left = lowestCommonAncestor(root->left, p, q, result);
        TreeNode* right = lowestCommonAncestor(root->right, p, q, result);
        
        if ((left != NULL && right != NULL) || (root == p || root == q))
            result = root;
        
        return result == NULL ? (left != NULL ? left : right) : result;
    }
};