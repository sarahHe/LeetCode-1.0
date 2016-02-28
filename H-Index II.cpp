// The basic idea of this solution is to use binary search to find the minimum index such that
// citations[index] >= length(citations) - index
// After finding this index, the answer is length(citations) - index

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left=0, len = citations.size(), right= len-1,  mid;
        while(left<=right)
        {
            mid=(left+right)>>1;
            if(citations[mid]== (len-mid)) return citations[mid];
            else if(citations[mid] > (len-mid)) right = mid - 1;
            else left = mid + 1;
        }
        return len - left;
    }
};
