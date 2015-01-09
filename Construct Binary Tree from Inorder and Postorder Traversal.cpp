//Be very careful to the root_pos!!!!!
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
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int start, int end, int root_pos) {
        if (start >= inorder.size() || end < 0 || start > end) return NULL;
        if (start == end)
            return new TreeNode(inorder[start]);
        
        TreeNode *root = new TreeNode(postorder[root_pos]);
        int i = start;
        for (; i <= end; i++) {
            if (inorder[i] == postorder[root_pos])
                break;
        }
        
        root->left = helper(inorder, postorder, start, i - 1, root_pos
                         - 1 - end + i);
        root->right = helper(inorder, postorder, i + 1, end, root_pos - 1);
        
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() != postorder.size()
            || inorder.size() == 0)
            return NULL;
        
        return helper(inorder, postorder, 0, inorder.size() - 1, inorder.size() - 1);
    }
};
