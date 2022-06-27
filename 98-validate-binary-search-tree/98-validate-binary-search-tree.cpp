/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root->left, NULL, root) && isValid(root->right, root, NULL);
    }
    
    bool isValid(TreeNode* root, TreeNode* minRange, TreeNode* maxRange) {
        if (root == NULL) return true;
        
        if ((minRange == NULL || root->val > minRange->val) && (maxRange == NULL || root->val < maxRange->val))
            return isValid(root->left, minRange, root) && isValid(root->right, root, maxRange);
            
        return false;
    }
};