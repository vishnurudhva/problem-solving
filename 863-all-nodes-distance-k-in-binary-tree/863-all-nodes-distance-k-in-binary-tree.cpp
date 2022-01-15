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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        unordered_map<TreeNode*, TreeNode*> map;
        unordered_map<TreeNode*, bool> visited;
        makeMap(root, map);
        
        queue<TreeNode*> q;
        q.push(target);
        while(q.size()) {
            int size = q.size();
            if(k == 0) break;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                visited[node] = true;
                q.pop();
                if(node->left != NULL && !visited[node->left]) q.push(node->left);
                if(node->right != NULL && !visited[node->right]) q.push(node->right);
                if(map.find(node) != map.end() && !visited[map[node]]) q.push(map[node]);
            }
            k--;
        }
        while(q.size()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
    
    void makeMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& map) {
        if(root == NULL) return;
        if(root->left != NULL)
            map[root->left] = root;
        if(root->right != NULL)
            map[root->right] = root;
        makeMap(root->left, map);
        makeMap(root->right, map);
    }
};