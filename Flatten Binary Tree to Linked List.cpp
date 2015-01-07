/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void preOrder(TreeNode *root, stack<TreeNode*> &s) {
        if (!root)  return;
        
        s.push(root);
        preOrder(root->left, s);
        preOrder(root->right, s);
    }
    
    void flatten(TreeNode *root) {
        if (!root)  return;
        
        stack<TreeNode*> s;
        preOrder(root, s);
        root = s.top();
        s.pop();
        while (!s.empty()) {
            TreeNode *node = root;
            root = s.top();
            root->right = node;
            root->left = NULL;
            s.pop();
        }
    }
};
