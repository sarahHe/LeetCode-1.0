// Determine whether an integer is a palindrome. Do this without extra space.
class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        if (x < 0)  return false; // negative number is not palindrome
        
        int base = 1;
        while (x / base >= 10) // notice base >= 10
            base *= 10;
            
        while (x) {
            int left = x / base,
                right = x % 10;
            if (left != right)
                return false;
            
            x -= left * base; //remove the lestmost one
            base /= 100; //every iteration remove two digits
            x /=10;// remove the rightmost one
        }
        return true;
    }
};
