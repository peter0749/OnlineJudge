class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<unsigned short> temp(num1.length()+num2.length(), 0);
        
        for (int j=0; j<num2.length(); ++j) {
            for (int i=0; i<num1.length(); ++i) {
                int d1 = num1[i]-'0';
                int d2 = num2[j]-'0';
                int mul = d1 * d2 + temp[i+j];
                temp[i+j+1] += mul/10;
                temp[i+j] = mul%10;
            }
        }
        
        int seekIdxNonZero = temp.size()-1;
        while (seekIdxNonZero >= 0 && temp[seekIdxNonZero]==0) --seekIdxNonZero;
        
        string result;
        for (;seekIdxNonZero >= 0; --seekIdxNonZero) result += (temp[seekIdxNonZero]+'0');
        
        if (result.length() == 0)
            result = "0";
        
        return result;
    }
};
