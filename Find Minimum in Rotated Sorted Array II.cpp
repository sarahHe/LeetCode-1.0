// Follow up for "Find Minimum in Rotated Sorted Array":
// What if duplicates are allowed?
// Would this affect the run-time complexity? How and why?

class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0, right = num.size()-1;
        while (left < right) {
            if (num[left] < num[right]) //means sorted!!
                return num[left];
            
            int mid = left + (right - left)/2;
            if (num[mid] < num[right]) {
                right = mid;
                while (num[right] == num[right-1] && right > left)
                    right--;
            }
            else if (num[mid] > num[right]){
                left = mid + 1;
                while (num[left] == num[left+1] && left < right)
                    left++;
            }
            else {
                if ((mid > 0 && num[mid] == num[mid-1]) || (mid == 0))
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return num[left];
    }
};
