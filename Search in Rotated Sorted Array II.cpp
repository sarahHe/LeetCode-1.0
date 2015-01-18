/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.

Deal with duplicates: some while loop
*/
class Solution {
public:
    bool search(int A[], int n, int target) {
        int i = 0, j = n - 1;
        while (i <= j) {///////注意这里的边界
            int mid = i + (j-i)/2;
            if (A[mid] > target) {
                if (A[i] > target) {
                    i = i + 1;// 不能简单地只用i = mid + 1. 如果target是最小的那个数，就会找不到了
                    while (i < j && A[i+1] == A[i])
                        i++;
                }
                else if (A[i] < target) {
                    j = mid - 1;
                    while (i < j && A[j-1] == A[j])
                        j--;
                }
                else
                    return true;
            }
            else if (A[mid] < target) {
                if (A[j] > target) {
                    i = mid + 1;
                    j = j - 1;
                    while (i < j && A[i+1] == A[i])
                        i++;
                    while (i < j && A[j-1] == A[j])
                        j--;
                }
                else if (A[j] < target) {
                    j = j - 1;
                    while (i < j && A[j-1] == A[j])
                        j--;
                }
                else
                    return true;
            }
            else
                return true;
            
        }
        return false;
    }
};
