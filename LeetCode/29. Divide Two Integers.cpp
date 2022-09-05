class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = ((dividend<0) & (divisor>0)) || ((dividend>0) & (divisor<0));
        
        unsigned int u_dividend, u_divisor;
        
        if (dividend < 0) {
            u_dividend = dividend==INT_MIN ? (1u<<31) : -dividend;
        } else {
            u_dividend = dividend;
        }
        
        if (divisor < 0) {
            u_divisor = divisor==INT_MIN ? (1u<<31) : -divisor;
        } else {
            u_divisor = divisor;
        }
        
        unsigned int bit_length = 0;
        unsigned int temp = u_divisor;
        while(temp) {
            ++bit_length;
            temp >>= 1;
        }
        
        unsigned int result = 0x0000;
        for (int i=32-bit_length; i>=0; --i) {
            temp = (u_divisor<<i);
            if (temp<=u_dividend) {
                result = result | (1u<<i);
                u_dividend = u_dividend - temp;
            }
        }
        if (neg) {
            return result > (1u<<31) ? INT_MIN : -result;
        } else {
            return result > INT_MAX ? INT_MAX : result;
        }
    }
};
