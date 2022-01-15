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
    void dfs(TreeNode* root, int& result, TreeNode* par_max) {
        if(root == NULL) return;
        if(par_max && root->val >= par_max->val) {
            result++;
            par_max = root;
        }
        
        dfs(root->left, result, par_max);
        dfs(root->right, result, par_max);
    }
    int goodNodes(TreeNode* root) {
        int result = 0;
        dfs(root, result, root);
        return result;
    }
};