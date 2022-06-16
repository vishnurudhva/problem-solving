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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        stack<TreeNode*> stk;
        unordered_map<TreeNode*, int> visited;
        stk.push(root);
        
        while(!stk.empty()) {
            TreeNode* topNode = stk.top();
            
            
            if (topNode->left && visited.find(topNode->left) == visited.end()) {
                stk.push(topNode->left);
                continue;
            }
            
            
            if (topNode->right && visited.find(topNode->right) == visited.end()) {
                stk.push(topNode->right);
                continue;
            }
            
            int leftDepth = 0, rightDepth = 0;
            if (topNode->left && visited.find(topNode->left) != visited.end())
                leftDepth = visited[topNode->left];
            
            if (topNode->right && visited.find(topNode->right) != visited.end())
                rightDepth = visited[topNode->right];
            if (abs(leftDepth - rightDepth) > 1) return false;
            visited[topNode] = 1 + max(leftDepth, rightDepth);
            stk.pop();
        }
        
        return true;
    }
};