bool helper(TreeNode* root, int &count) {
    if (!root)  return true;
    
    bool bLeft = helper(root->left, count);
    bool bRight = helper(root->right, count);
    if (bLeft && bRight) {
        if (root->left && root->left->val != root->val)
            return false;
        if (root->right && root->right->val != root->val)
            return false;
        
        count++;
        return true;
    }
    return false;
}

int countUnivalSubtrees(TreeNode *root) {
    int count = 0;
    helper(root, count);
    return count;
}
