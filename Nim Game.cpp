class Solution {
public:
    bool canWinNim(int n) {
        // death number is 4N
        return n % 4 != 0;
    }
};
