// Classic binary search problem.

// Looking at subarray with index [start,end]. We can find out that if the first member is less than the last member, 
//there's no rotation in the array. So we could directly return the first element in this subarray.

//只要有rotate 最左 > 最右
//中间的 》 最左 =》rotate部分在右边
//否则 rotate在左边
class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r = num.size()-1;
        while (l < r) {
            if (num[l] < num[r])    
                return num[l]; // reduce time from 16ms to 8ms.
            int m = l + (r-l)/2;
            if (num[m] > num[r])
                l = m+1;
            else
                r = m;
        }
        return num[l];
    }
};
