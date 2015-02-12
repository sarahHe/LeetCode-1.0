// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

class Solution {
//     这个方法运行的时候，当遇到height[2] == 5的时候，发现其比之前一个高度小，则从当前值（5）开始，向左搜索比当前值小的值。当搜索到最左边（2）时，比5小，此时计算在height[0]和height[2]之间的最大面积，注意不包括height[0]和和height[2]。height[1]以红色标出的这个区域就被计算完成。同样的方法，计算出绿色和粉色的面积。
//     因此这个方法需要使用两个栈。第一个栈为高度栈heightStack，用于记录还没有被计算过的连续递增的序列的值。第二个栈为下标栈indexStack，用于记录高度栈中对应的每一个高度的下标，以计算宽度。

// 算法具体执行的步骤为：
//     若heightStack为空或者当前高度大于heightStack栈顶，则当前高度和当前下标分别入站（下面有一个解法可以只用一个栈即可，用栈来保存下标，而高度由下标很容易得到）。所以heightStack记录了一个连续递增的序列。
//     若当前高度小于heightStack栈顶，heightStack和indexStack出栈，直到当前高度大于等于heightStack栈顶。出栈时，同时计算区间所形成的最大面积。注意计算完之后，当前值入栈的时候，其对应的下标应该为最后一个从indexStack出栈的下标。比如height[2]入栈时，其对应下标入栈应该为1，而不是其本身的下标2。如果将其本身下标2入栈，则计算绿色区域的最大面积时，会忽略掉红色区域。
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.size() == 0)
            return 0;
            
        int area = height[0];
        vector<int> tmp = height;// Important
        tmp.push_back(0);  // Important for the last one
        stack<int> s; //store idx
        for (int i = 0; i < tmp.size(); i++) {
            if (s.empty() ||
                (!s.empty() && tmp[s.top()] <= tmp[i]))
                s.push(i);
            else {
                while (!s.empty() && (tmp[s.top()] > tmp[i])) {
                    int idx = s.top();
                    s.pop(); //important
                    int width = s.empty() ? i : i - s.top() - 1; 
                    // you can't gaurantee s.top() is 0 or a certain number
                    area = max(area, width * tmp[idx]);
                }
                s.push(i);
            }
        }
        return area;
    }
};
