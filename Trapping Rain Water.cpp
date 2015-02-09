// Given n non-negative integers representing an elevation map where 
// the width of each bar is 1, compute how much water it is able to trap after raining.

// 这里计算面积不用一般几何书的方法，这里是两边往中间遍历，记录当前第二高点secHight，
// 然后利用这个第二高点减去当前历经的柱子，剩下就装水容量了。
// 为什么是第二高点？因为两边比较，最高的点不用动，只移动第二高点。
class Solution {
public:
    int trap(int A[], int n) {
        int secHight = 0;
		int left = 0;
		int right = n-1;
		int area = 0;
		while (left < right){
			if (A[left] < A[right]){
				secHight = max(A[left], secHight);
				area += secHight-A[left];//计算当前格的能装雨水的容量
				left++;
			} else {
				secHight = max(A[right], secHight);
				area += secHight-A[right];
				right--;
			}
		}
		return area;
    }
};
