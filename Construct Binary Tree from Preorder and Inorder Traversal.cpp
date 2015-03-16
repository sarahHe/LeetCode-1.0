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
    //p is the index of the root in preorder
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int p, int start, int end) {
        //if care about the coding style, could create a struct, which contains p, start and end.
        if (p == preorder.size() || end < 0 || start > end) return NULL;
            
        TreeNode *root = new TreeNode(preorder[p]);
        if (start == end)   return root; // important, early terminate
        
        //find the position of root in inorder
        int i = start;
        while (i <= end && inorder[i] != preorder[pos])
            i++;
        
        //every node in the left tree is to the left of the root(i), the same with right
        root->left = helper(preorder, inorder, p + 1, start, i - 1);
        //the root for the right part is 1st node in the right part
        root->right = build_helper(preorder, inorder, pos + (i - start) + 1, i + 1, end); //right
        // pos + len(left_tree) + 1
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return helper(preorder, inorder, 0, 0, preorder.size() - 1); 
        //it's better for end to be the last accesible index
    }
};
