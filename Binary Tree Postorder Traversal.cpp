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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root)  return res;
        
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *visited = root;
        while(!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            if ((!node->right && !node->left) 
                || (node->left && node->left == visited) 
                || (node->right && node->right == visited)
            ) {
                res.push_back(node->val);
                visited = node;
            }
            else {
                s.push(node);
                if (node->right && node->right != visited)
                    s.push(node->right);
                if (node->left && node->left != visited)
                    s.push(node->left);
                }
        }
        return res;
    }
};


2015.4.25 update
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        //two stack solution
        stack<TreeNode*> s, out;
        vector<int> res;
        if (!root)  return res;
        
        s.push(root);
        while(!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            out.push(node);
            if (node->left)
                s.push(node->left);
            if (node->right)
                s.push(node->right);
        }
        
        while(!out.empty()) {
            res.push_back(out.top()->val);
            out.pop();
        }
        return res;
    }
};
