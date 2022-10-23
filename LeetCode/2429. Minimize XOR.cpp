class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt2 = 0;
        while (num2) {
            cnt2 += num2&1;
            num2>>=1;
        }
        int temp = num1;
        int largest_bit = 0;
        while (temp) {
            ++largest_bit;
            temp>>=1;
        }
        // temp = 0;
        for (int i=largest_bit-1; i>=0 && num1 && cnt2>0; --i) {
            if (num1 & (1<<i)) {
                num1 ^= (1<<i);
                temp |= (1<<i);
                --cnt2;
            }
        }
        // 32-bit signed int
        for (int i=0; i<31 && cnt2>0; ++i) {
            if ((temp & (1<<i)) == 0) {
                temp |= (1<<i);
                --cnt2;
            }
        }
        return temp;
    }
};
