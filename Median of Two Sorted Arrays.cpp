// O(n)的解法比较直观，直接merge两个数组，然后求中间值。而对于O(log(m+n))显然是用二分搜索了， 相当于“Kth element in 2 sorted array”的变形。如果(m+n)为奇数，那么找到“(m+n)/2+1 th element in 2 sorted array”即可。如果（m+n）为偶数，需要找到(m+n)/2 th 及(m+n)/2+1 th，然后求平均。
// 而对于“Kth element in 2 sorted array”， 如下图，两个中位数 A[m/2] 和 B[n/2]， 可以将数组划分为四个部分。而丢弃哪一个部分取决于两个条件：1， (m/2 + n/2)?k；2，A[m/2] ? B[n/2];
// 简单的说，就是或者丢弃最大中位数的右区间，或者丢弃最小中位数的左区间。

class Solution {
public:
    double solve(int A[], int m, int B[], int n, int TopK) {
        if (m > n) {
            return solve(B, n, A, m, TopK);
        }
        if (m == 0) {
            return (double)(B[TopK - 1]);
        }
        if (TopK == 1) {
            return min(A[0], B[0]);
        }
        int amid = min(m, TopK / 2);
        int bmid = TopK - amid;
        if (A[amid - 1] < B[bmid - 1]) {
            return solve(A + amid, m - amid, B, n, TopK - amid);
        }
        if (A[amid - 1] > B[bmid - 1]) {
            return solve(A, m, B + bmid, n - bmid, TopK - bmid);
        }
        return (double)(A[amid - 1]);
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) % 2) {
            return solve(A, m, B, n, (m + n + 1) / 2);
        } else {
            return 0.5 * (solve(A, m, B, n, (m + n) / 2) + solve(A, m, B, n, (m + n) / 2 + 1));
        }
    }
};
