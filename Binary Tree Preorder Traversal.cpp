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



//2016.3.6 
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    vector<int> res;
    
    while (root || !s.empty()) {
        while (root) {
            s.push(root);
            res.push_back(root->val);
            root = root->left;
        }
        
        TreeNode *node = s.top();
        s.pop();
        root = node->right;
    }
    return res;
}
