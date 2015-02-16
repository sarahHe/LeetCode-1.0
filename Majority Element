class Solution {
public:
    int majorityElement(vector<int> &num) {
        unordered_map<int, int> h;
        for (int i = 0; i < num.size(); i++) {
            if (!h[num[i]])
                h[num[i]] = 1;
            else
                h[num[i]]++;
            if (h[num[i]] > num.size()/2)
                return num[i];
        }
    }
};

// Runtime: O(n log n) — Sorting: As we know more than half of the array are elements of the same value, we can sort the array and all majority elements will be grouped into one contiguous chunk. Therefore, the middle (n/2th) element must also be the majority element.

// Runtime: O(n) — Moore voting algorithm: We maintain a current candidate and a counter initialized to 0. As we iterate the array, we look at the current element x:
// If the counter is 0, we set the current candidate to x and the counter to 1.
// If the counter is not 0, we increment or decrement the counter based on whether x is the current candidate.
// After one pass, the current candidate is the majority element. Runtime complexity = O(n).
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int cur = 0, count = 0;
        for (int i = 0; i < (int)num.size(); i++) {
            if (count == 0) {
                cur = num[i];
                count++;
            }
            else {
                if (cur == num[i])
                    count++;
                else 
                    count--;
            }
        }
        return cur;
    }
};
