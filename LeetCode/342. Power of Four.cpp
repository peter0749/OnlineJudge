class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        if (!(n&3) && isPowerOfFour(n>>2)) return true;
        return false;
    }
};
