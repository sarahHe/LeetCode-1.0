// 思路1：递归，放与不放的问题。
// 思路2：只要我们能找到比原问题规模小却同质的问题，都可以用递归解决。比如要求{1, 2, 3}的所有子集，可以先求{2, 3}的所有子集，{2, 3}的子集同时也是{1, 2, 3} 的子集，然后我们把{2, 3}的所有子集都加上元素1后（注意排序），又得到同样数量的子集， 它们也是{1, 2, 3}的子集。这样一来，我们就可以通过求{2, 3}的所有子集来求 {1, 2, 3}的所有子集了。即为求1,2,3的子集，要先求2,3的子集，然后再把1加入到2,3的子集中去，典型的递归思路
class Solution {
public:
    void generate(vector<int> &S, int pos, vector<int> tmp, vector<vector<int> > &res) {
        if (pos == S.size()) {
            res.push_back(tmp);
            return;
        }
        generate(S, pos+1, tmp, res);
        tmp.push_back(S[pos]);
        generate(S, pos+1, tmp, res);
    }

    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > res;
        vector<int> tmp;
        generate(S, 0, tmp, res);
        return res;
    }
};
