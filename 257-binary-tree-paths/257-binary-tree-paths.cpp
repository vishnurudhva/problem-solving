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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        binaryTreePathsHelper(root, "", result);
        return result;
    }
    
    vector<string> binaryTreePathsHelper(TreeNode* root, string current, vector<string>& result) {
        current += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            result.push_back(current);
            return result;
        }
        if(root->left != NULL) binaryTreePathsHelper(root->left, current + "->", result);
        if(root->right != NULL) binaryTreePathsHelper(root->right, current + "->", result);
        return result;
    }
};