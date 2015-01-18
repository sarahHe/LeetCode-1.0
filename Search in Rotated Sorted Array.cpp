/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.

二分的思想
*/

class Solution {
public:
    int search(int A[], int n, int target) {
        int i = 0, j = n - 1;
        while (i <= j) {///////注意这里的边界
            int mid = i + (j-i)/2;
            if (A[mid] > target) {
                if (A[i] > target) 
                    i = i + 1;// 不能简单地只用i = mid + 1. 如果target是最小的那个数，就会找不到了
                else if (A[i] < target)
                    j = mid - 1;
                else
                    return i;
            }
            else if (A[mid] < target) {
                if (A[j] > target) {
                    i = mid + 1;
                    j = j - 1;
                }
                else if (A[j] < target)
                    j = j - 1;
                else
                    return j;
            }
            else
                return mid;
                
        }
        return -1;
    }
};
