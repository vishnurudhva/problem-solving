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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> result;
        
        queue<TreeNode*> bfs;
        bfs.push(root);
        while(!bfs.empty())
        {
            vector<int> ans;
            int size = bfs.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = bfs.front();
                if(node->left) bfs.push(node->left);
                if(node->right) bfs.push(node->right);
                ans.push_back(node->val);
                bfs.pop();
            }
            result.push_back(ans);
        }
        return result;
    }
};