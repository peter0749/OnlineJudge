class Solution {
private:
    inline bool is_numeric(char c) {
        return (c-'0'>=0) && (c-'0'<=9);
    }
public:
    int myAtoi(string s) {
        int i=0;
        for (; i<s.length() && s[i]==' '; ++i);
        if (i==s.length()) return 0;
        int sign = 1;
        if (s[i]=='+'||s[i]=='-'){
            sign = (s[i]=='+')?1:-1;
            ++i;
        }
        if (i==s.length()) return 0;
        int sum = 0;
        for (;i<s.length() && is_numeric(s[i]); ++i) {
            if (sign>0 && sum > INT_MAX/10) return INT_MAX;
            if (sign<0 && sum < INT_MIN/10) return INT_MIN;
            sum *= 10;
            int digit = sign * (s[i]-'0');
            if (sign>0 && sum > INT_MAX-digit) return INT_MAX;
            if (sign<0 && sum < INT_MIN-digit) return INT_MIN;
            sum += digit;
        }
        return sum;
    }
};
