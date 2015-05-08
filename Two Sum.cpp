/*
Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers 
(both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

有两种思路：hash table O(N)和排序O(logn)。
hash：对于每个数先在hashtable里面找 target与它的差 的那个数在不在，O(1)。
如果在那么就放在res里面 break 然后返回res。
如果不在，就在hashtable里面存下这个数。

2.排序：
numbers按非递减排序，设置两个游标idx1和idx2.
初始时，idx1指向第一个number，idx2指向最后一个number。
如果numbers[idx1]+numbers[idx2]==target，则要求的解为numbers[idx1]在原数列中的下标
（现在的numbers是已经排序后的）和numbers[idx2]在原数列中的下标；
如果numbers[idx1]+numbers[idx2]>target，则idx2--；
如果numbers[idx1]+numbers[idx2]<target，则idx1++。
*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res; // vector<int> res(2, -1);
        unordered_map<int, int> table;
        for (int i = 0; i < numbers.size(); i++) {
            if (table[target - numbers[i]]) {
                // res.push_back(min(i + 1,//注意这里的numbers[i]还没有存进去，
                //                         //所以用i+1来与存进去的那个来比。
                //                   table[target - numbers[i]]));
                // res.push_back(max(i + 1,
                //                   table[target - numbers[i]]));
                //因为是遍历一遍，所以i+1 肯定比table[target - numbers[i]]大
                res.push_back(table[target - numbers[i]]); //res[0] = my_map[target - nums[i]];
                res.push_back(i+1); //res[1] = i+1;
                break;
            }
            else
                table[numbers[i]] = i + 1;
        }
        return res;
    }
};
