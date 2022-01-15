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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        bfs(root, result,  0);
        return result;
    }
    
    void bfs(TreeNode* root, vector<vector<int>> &result, int i)
    {
        if(root == NULL) return;
        
        if(i >= result.size())
            result.push_back({root->val});
        else
            if(i % 2 == 0)
                result[i].push_back(root->val);
            else
                result[i].insert(result[i].begin(), root->val);
        bfs(root->left, result, i + 1);
        bfs(root->right, result, i + 1);
    }
};