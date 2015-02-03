// Given n, generate all structurally unique BST's 
// (binary search trees) that store values 1...n.

// the res stores the trees, which are in inorder
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
    vector<TreeNode *> gen(int l, int r) {
        vector<TreeNode*> res;
        if (l > r)
            res.push_back(NULL);
        
        for (int i = l; i <= r; i++) {
            vector<TreeNode*> left = gen(l, i - 1),
                              right = gen(i + 1, r);
            for (int m = 0; m < left.size(); m++) {
                for (int n = 0; n < right.size(); n++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[m];
                    root->right = right[n];
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode *> generateTrees(int n) {

        return gen(1, n);
    }
};
