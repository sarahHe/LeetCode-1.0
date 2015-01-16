//Given preorder and inorder traversal of a tree, construct the binary tree.

// be clear about how the tree will be constructed.
//use size_of_left_subTree to get the index
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
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int p, int start, int end) {
        //if care about the coding style, could create a struct, which contains p, start and end.
        if (p == preorder.size() || end < 0 || start > end) return NULL;
            
        TreeNode *root = new TreeNode(preorder[p]);
        if (start == end)   return root;
        int i = start;
        while (i <= end) {
            if (preorder[p] == inorder[i])
                break;
            i++;
        }
        int left_len = i - start;
        root->left = helper(preorder, inorder, p + 1, start, i - 1);
        root->right = helper(preorder, inorder, p + left_len + 1, i + 1, end);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return helper(preorder, inorder, 0, 0, preorder.size() - 1); 
        //it's better for end to be the last accesible index
    }
};
