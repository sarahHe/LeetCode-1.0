/*
Given an array S of n integers, find three integers in S such that 
the sum is closest to a given number, target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

先对数组排个序。枚举第一个数，然后设两个指针，在第一个数的后半段开始王中间收缩，
if sum > target则右指针往左移， if sum < target则左指针往右移。
排序O(nlogn) + 查找O(n^2) = O(n^2)
*/
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end()); //注意sort的语法
        int res = num[0] + num[1] + num[2]; 
        for (int i = 0; i < num.size() - 2; i++) {//这里的i还是要从0开始！！不能从3开始
            if (num[i] == num[i - 1])   continue;
            
            int start = i + 1, end = num.size() - 1;
            while (start < end) {
                int sum = num[i] + num[start] + num[end];
                if (abs(target - sum) < abs(target - res))
                    res = sum;
                if (sum == target)
                    return sum;
                else if (sum > target)
                    end--;
                else 
                    start++;
            }
        }
        return res;
    }
};
