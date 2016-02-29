//Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
//Note: Given target value is a floating point. You may assume k is always valid, that is: 
//k ≤ total nodes. You are guaranteed to have only one unique set of k values in the BST that are closest to the target. 
//Follow up: Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

//二叉搜索树的中序遍历就是顺序输出二叉搜索树，所以我们只要中序遍历二叉搜索树，同时维护一个大小为K的队列，
//前K个数直接加入队列，之后每来一个新的数（较大的数），如果该数和目标的差，相比于队头的数离目标的差来说，
//更小，则将队头拿出来，将新数加入队列。如果该数的差更大，则直接退出并返回这个队列，因为后面的数更大，差值也只会更大。

class Solution {
public:
    List<int> closestKValues(TreeNode *root, double target, int k) {
        List<int> res;
        stack<TreeNode*> s;
        while (root) {
            s.push(root);
            root = root->left;
        }

        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();

            // 维护一个大小为k的队列
            // 队列不到k时直接加入
            if (res.size() < k)
                res.push_back(cur->val);
            else {
                // 队列到k时，判断下新的数是否更近，更近就加入队列并去掉队头
                int first = res.back();
                if (abs(cur->val - target) < abs(first - target)) {
                    res.push_back(cur->val);
                    res.erase(first);
                }
                else // 如果不是更近则直接退出，后面的数只会更大
                    break;
            }

            if (cur->right) {
                cur = cur->right;
                while (cur) {
                    s.push(cur->val);
                    cur = cur->left;
                }
            }
        }
        return res;
    }
}
