// 令f[n]表示：n个节点有f(n)棵二叉搜索树。
// 假设已知f[0]~f[n]，求f[n+1]：
// n+1个节点中有一个是根节点，根节点下左子树设为L，右子树设为R。
// Ln表示左子树节点个数，Rn表示右子树节点个数，则Ln + Rn + 1（根节点） = n + 1（总节点个数），即Ln + Rn = n。
// 那么左子树有f[Ln]种情况，右子树有f[Rn]种情况，因此f[n + 1] = Sigma(f[Ln] * f[Rn])。
class Solution {
public:
    int numTrees(int n) {
        vector<int> tree(n+1, 0);
        tree[0] = 1;
        tree[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                tree[i] += (tree[j - 1] * tree[i - j]);
            }
        }
        return tree[n];
    }
};
