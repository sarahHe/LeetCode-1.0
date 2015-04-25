/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
2015.4.25 update
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        //one stack solution
        vector<int> res;
        if (!root)  return res;
        
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *pre = nullptr;
        while (!s.empty()) {
            TreeNode *node = s.top();
            if ((!node->left && !node->right) ||
                (node->left && node->left == pre) ||
                (node->right && node->right == pre)) {
                    s.pop();
                    res.push_back(node->val);
                    pre = node;
                    continue; // improve the effeciency
                }
            
            if (node->right && node->right != pre) //right push first so pop later
                s.push(node->right);
            if (node->left && node->left != pre)
                s.push(node->left);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        //two stacks solution
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
