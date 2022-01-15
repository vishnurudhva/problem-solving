/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        connectnode(root->left, root->right);
        return root;
    }
    
    void connectnode(Node* root1, Node* root2)
    {
        if(root1 == NULL) return;
        root1->next = root2;
        connectnode(root1->left, root1->right);
        connectnode(root2->left, root2->right);
        connectnode(root1->right, root2->left);
    }
};