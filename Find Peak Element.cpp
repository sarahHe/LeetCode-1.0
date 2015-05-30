// 因为按照题意，num[0]是大于左边的不存在的那个元素的，num[size-1]也是大于右边那个不存在的元素的，
// 假如不存在，那么就会有num[0]<num[1]，num[1]<num[2]，就是增序，num[size-2]<num[size-1]，
// 这样num[size-1]就是peak elem了，所以一定存在。
// 于是就是这样的思路，num[NULL] < num[0],我们假设左边的元素小于右边的元素，
// 那么第一个左边元素大于右边的那个一定是peak elem.如num[0].为什么第一个就是呢？因为前面的都是左<右，判断左>右为false。
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int l = 0, r = num.size() - 1;
        while (l < r) {
            int m = l + (r-l)/2;
            if (num[m] > num[m+1])
                r = m;
            else 
                l =  m + 1;
        }
        return l;
    }
};


2015.5.29 update
//other's solution
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        for(int i = 1; i < num.size(); i ++)
        {
            if(num[i] < num[i-1])
            {// <
                return i-1;
            }
        }
        return num.size()-1;
    }
};
