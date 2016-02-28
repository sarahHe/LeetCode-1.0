//Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
//Note:
//Given target value is a floating point.
//You are guaranteed to have only one unique value in the BST that is closest to the target.

int closestValue(TreeNode* root, double target) {
    TreeNode *node = root->val < targe : root->right : root->left;
    if (!node)  return root->val;

    int closerVal = closestValue(node, target);
    return abs(closerVal - target) < abs(root->val - target) ? closerVal : root->val;
}
