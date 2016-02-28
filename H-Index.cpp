这道题让我们求H指数，这个质数是用来衡量研究人员的学术水平的质数，定义为一个人的学术文章有n篇分别被引用了n次，那么H指数就是n。
//而且wiki上直接给出了算法，可以按照如下方法确定某人的H指数：1、将其发表的所有SCI论文按被引次数从高到低排序；
//2、从前往后查找排序后的列表，直到某篇论文的序号大于或等于该论文被引次数。所得序号减一即为H指数。

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); i++) {
            if (i >= citations[i])
                return i;
        }
        return citations.size();
    }
};



//The idea is to see that the result can only range from 0 to the length of the array 
//(because we can't have h-index greater than the total papers published). 
//So we create an array "arr" which acts like a HashMap (using pigeon hole principle) and 
//loop backwards from the highest element, then we find "tot" which is the total number of 
//papers that has more than i citations, and we stop when tot>=i (total number of papers with more than i citations >= i). 
//We don't need to keep going because we are trying the biggest i possible, we we stop and return the result.

class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> count(citations.size() + 1, 0);
        for (auto i : citations) {
            if (i >= citations.size())
                count[citations.size()]++;
            else
                count[i]++;
        }
        
        int tot = 0;
        for (int i = citations.size(); i >= 0; i--) {
            tot += count[i];
            if (tot >= i)
                return i;
        }
        return 0;
    }
};
