class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            if (res > 214748364 || res < -214748364)
            return 0;
                
            res = res * 10 + x%10;
            x /= 10;
        }
        return res;
    }
};

2015.5.25 update
int reverse(int x) {
    long long res = 0; // must change it to long long!!
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return (res < INT_MIN || res > INT_MAX) ? 0 : res;
}
