class Solution {
public:
    // Ugly Code...
    inline pair<long long,long long> nextDigit(long long numerator, long long denominator) {
        long long temp = numerator / denominator;
        // cout << numerator << " " << denominator << " " << temp << endl;
        numerator -= temp * denominator;
        numerator *= 10LL;
        return make_pair(numerator, temp);
    }
    inline int sign(int x) {
        if (x==0)
            return 0;
        if (x<0)
            return -1;
        return 1;
    }
    string fractionToDecimal(int numerator, int denominator) {
        
        if (numerator == 0)
            return "0";
        
        string outputSign = sign(numerator) == sign(denominator) ? "" : "-";
        string s;
        
        long long n_ll = numerator;
        long long d_ll = denominator;
        
        n_ll = abs(n_ll);
        d_ll = abs(d_ll);
        
        int offset = 0;
        if (n_ll / d_ll > 0LL) {
            long long temp = n_ll / d_ll;
            string num = to_string(temp);
            s += num;
            n_ll -= temp * d_ll;
            n_ll *= 10LL;
            offset = num.length();
        }
        
        map<pair<long long,long long>,int> index;
        pair<long long,long long> temp(n_ll,0LL);
        
        for (int i=0; i<10005; ++i) {
            temp = nextDigit(temp.first, d_ll);
            if (index.count(temp))
                break;
            index[temp] = i;
            s += to_string(temp.second);
        }
        
        if (index.count(temp)) {
            if (index[temp] == s.length()-offset-1 && s[s.length()-1]=='0')
                s = s.substr(0, s.length()-1);
            else {
                s.insert(offset+index[temp], "(");
                s += ")";
            }
        }
        
        if (offset) {
            if (offset < s.length())
                s.insert(offset, ".");
        }
        else
            s.insert(1, ".");
        
        return outputSign+s;
    }
};
