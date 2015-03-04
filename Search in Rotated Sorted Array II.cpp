/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.

Deal with duplicates: some while loop
*/
// 较上个题只需少量改动，但是复杂度已经是O(N)了，其实直接用线性搜索
class Solution {
public:
    bool search(int A[], int n, int target) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (A[mid] == target)
                return true;
            else if (A[mid] < A[high]) { //pay attention to the condition
                if (A[mid] < target && target <= A[high]) //pay attention to the =
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else if (A[mid] > A[high]){ 
                if (A[mid] > target && target >= A[low]) // pay attention to the second comparision
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else  //if (A[mid] == A[high])  pay attention to this condition
                high--;
        }
        return false;
    }
};
