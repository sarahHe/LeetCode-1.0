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
    TreeNode *build_helper(vector<int> &inorder, vector<int> &postorder, int pos, int start, int end) {
        if (start < 0 || end == inorder.size() || start > end)
            return NULL;
            
        TreeNode *root = new TreeNode(postorder[pos]);
        if (start == end)   return root;
        
        int i = start;
        while (i <= end && inorder[i] != postorder[pos])
            i++;
            
        root->left = build_helper(inorder, postorder, pos - (end - i) - 1, start, i - 1);
        root->right = build_helper(inorder, postorder, pos - 1, i + 1, end);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build_helper(inorder, postorder, inorder.size() - 1, 0, inorder.size() - 1);
    }
};



2015.5.24 update
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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int pos, int start, int end) {
        //start for left, end for right
        if (start > end)    return NULL; //enough
        
        int i = start;
        while (i <= end && inorder[i] != postorder[pos])
            i++;
        TreeNode* node = new TreeNode(inorder[i]);
        int right_len = end - i + 1; //including root
        node->left = build(inorder, postorder, pos - right_len, start,  i - 1);
        node->right = build(inorder, postorder, pos - 1, i + 1, end); //better not use --pos, sometimes cause trouble here
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if (n == 0) return NULL;
        return build(inorder, postorder, n-1, 0, n-1);
    }
};
