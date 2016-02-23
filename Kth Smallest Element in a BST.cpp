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
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        res = 0;
        helper(root);
        return res;
    }
private:
    int count, res;
    void helper(TreeNode *root) {
        if (root->left)
            helper(root->left);
            
        count--;
        if (count == 0) {
            res = root->val;
            return;
        }
        
        if (root->right)
            helper(root->right);
    }
};
