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
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> q;
        q.push(root);
        int result = 0;
        while(q.size() > 0)
        {
            TreeNode* val = q.front();
            if(val != NULL && val->val >= low && val->val <= high) result += val->val;
            q.pop();
            if(val != NULL) q.push(val->left);
            if(val != NULL) q.push(val->right);
        }
        return result;
    }
};