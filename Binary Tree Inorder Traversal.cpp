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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root)  return res;
        
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            while (root->left) {
                root = root->left;
                s.push(root);
            }
            root = s.top();
            res.push_back(root->val);
            s.pop();
            
            while (!root->right && !s.empty()) {
                root = s.top();
                res.push_back(root->val);
                s.pop();
            }
            if (root->right) {
                root = root->right;
                s.push(root);
            }
            
        }
        return res;
    }
};


2015.5.25 update
//using stack
//can't understand morris algorithm
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode *cur = root;
        while (!s.empty() || cur) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                TreeNode *node = s.top();
                s.pop();
                res.push_back(node->val);
                cur = node->right;
            }
        }
        return res;
    }
};



//2016.3.6
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    while (root || !s.empty()) {
        while (root) {
            s.push(root);
            root = root->left;
        }
        
        TreeNode *node = s.top();
        res.push_back(node->val);
        s.pop();
        root = node->right;
    }
    return res;
}
