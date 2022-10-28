class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string s;
        int L = max(a.length(), b.length());
        int carry=0;
        for (int i=0; i<L; ++i) {
            int d1 = i<a.length()?(a[i]-'0'):0;
            int d2 = i<b.length()?(b[i]-'0'):0;
            int temp = d1+d2+carry;
            carry = temp/2;
            s += (temp%2) + '0';
        }
        if (carry)
            s += '1';
        reverse(s.begin(), s.end());
        return s;
    }
};
