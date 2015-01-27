// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along 
// the shortest path from the root node down to the nearest leaf node.

// memorize this
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
    int minDepth(TreeNode *root) {
        if (!root)  return 0; //if the tree is empty
        if (!root->right && !root->left)
            return 1;
        
        int leftDepth = minDepth(root->left),
            rightDepth = minDepth(root->right);
        if (leftDepth == 0)
            return rightDepth + 1; //easy to make mistake here
        if (rightDepth == 0)
            return leftDepth + 1;
        return min(leftDepth, rightDepth) + 1;
    }
};
