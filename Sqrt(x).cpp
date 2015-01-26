// Implement int sqrt(int x).

//二分法
class Solution {
public:
    int sqrt(int x) {
        int low = 0, high = x;
        while (low < high) {
            int mid = low + (high - low)/2 + 1;//如果没有+1， mid可能为0
            if (mid == x/mid)
                return mid;
            else if (mid > x/mid)
                high = mid - 1;
            else
                low = mid;
        }
        return high; //如果没有正好的根 就返回小的那个
        //从while循环中出来low >= high
    }
};
