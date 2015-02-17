/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

装水的容器，得是个长方形，宽由最短的边决定。
两个指针分别在两端，向中间收缩，这样能保证长方形的长只能变短，
*/
class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size()-1;
        int area = 0;
        while (i < j) {
            area = max(area, (j-i)*min(height[i], height[j]));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return area;
    }
};
