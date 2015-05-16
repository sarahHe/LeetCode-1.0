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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
            
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            res.push_back(root->val);
            if (cur->right) //因为是stack所以先右后左
                s.push(cur->right);
            if (cur->left) 
                s.push(cur->left);
        }
        return res;
    }
};
