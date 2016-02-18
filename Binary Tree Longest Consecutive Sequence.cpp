int longestConsecutive(TreeNode *root) {
	return longestHelper(root);
}

int longestHelper(TreeNode *parent, *TreeNode *child, int len) {
	if (!child)	return len;

	len = (parent->val + 1 == child->val) ? len + 1 : 1;
	return max(len, max(longestHelper(child, child->left, len), longestHelper(child, child->right, len)));
}
