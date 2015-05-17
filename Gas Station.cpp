//reference: http://blog.csdn.net/jellyyin/article/details/12245429
//思路：
//1. 每一站的代价为gas-cost, 也就是求从哪一站开始累加代价和总是大于0。一开始用了一个O（n^2）的解法，超时
//2. 如果所有站的代价和大于0，则所求的路线必定存在。
//如果总代价〉=0,从序号0开始求代价和，如果代价和小于0，则不是从本站或者本站之前
//的某一个代价大于0的站开始，必从下一站即之后的站开始，而且这样的站必定存在O（n）
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0, total = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) {
                start = (i + 1) % gas.size();
                sum = 0;
            }
        }
        if (total < 0)
            return -1;
        else
            return start;
    }
};


2015.5.17 update
//as long as the total gas is > cost, there must be a way.
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = gas.size() - 1, end = 0, sum = gas[start] - cost[start];
        while (start > end) {
            if (sum >= 0) { // >=
                sum += gas[end] - cost[end];
                end++;
            }
            else {
                start--; // start-- is before the next line
                sum += gas[start] - cost[start];
            }
        }
        return sum >= 0 ? start : -1;
    }
};
