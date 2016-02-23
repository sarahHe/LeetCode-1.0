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

 // DFS most preferable
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = nodeCount(root);
        if (k <= count)
            return kthSmallest(root->left, k);
        else if (k > count + 1)
            return kthSmallest(root->right, k - 1 - count); //1 is counted as current node
        else
            return root->val;
    }
    
    int nodeCount(TreeNode *root) {
        if (!root)
            return 0;
        return 1 + nodeCount(root->left) + nodeCount(root->right);
    }
};

//What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
//How would you optimize the kthSmallest routine?
//Answer: add a new property as the number of subnodes


