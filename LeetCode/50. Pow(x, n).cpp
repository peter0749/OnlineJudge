class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1;
        bool neg = n<0;
        unsigned int u_n;
        if (neg) {
            u_n = n==INT_MIN?1u<<31u:-n;
        } else {
            u_n = n;
        }
        double result = 1.0;
        double exp = neg?1.0/x:x; // x^1 or x^-1
        while(u_n) {
            if (u_n&1u) {
                result *= exp;
            }
            exp *= exp;
            u_n >>= 1u;
        }
        return result;
    }
};
