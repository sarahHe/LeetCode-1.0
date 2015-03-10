// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
class Solution {
public:
    void sortColors(int A[], int n) {
        int red = 0, blue = n -1, i = 0;
        while (i < n) { // the least condition
            if (A[i] == 0 && i > red) // i > red is a must
                swap(A[red++], A[i]);
            else if (A[i] == 2 && i < blue) // i < blue is a must
                swap(A[blue--], A[i]);
            else
                i++;
        }
    }
};
