// Implement an iterator over a binary search tree (BST). 
// Your iterator will be initialized with the root node of a BST.
// Calling next() will return the next smallest number in the BST.
//Note: next() and hasNext() should run in average O(1) time 
//and uses O(h) memory, where h is the height of the tree.

// Don't push all into a queue. Take advantage of the feature of inorder traversal 
// for each parent node, you look the left most child node
//Can't use BSTIterator as recusive function. It's a constructor

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode *> s;
public:
    BSTIterator(TreeNode *root) {
        pushLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *next = s.top();
        s.pop();
        pushLeft(next->right);
        return next->val;
    }
    
    void pushLeft(TreeNode *root) {
        if (!root)  return;
        
        s.push(root);
        while (root->left) {
            s.push(root->left);
            root = root->left;
            
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
