#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string preProcess(string &s) {
            if(s.empty()) return "^$";
            string res="^";
            for(string::size_type i=0; i!=s.length(); ++i) res+="#"+s.substr(i,1);
            return res+"#$";
        }

        string longestPalindrome(string &s) {
            string T=preProcess(s);
            int L = T.length();
            int *p = new int[T.length()];
            //fill(p, p+L, 0);
            int id=0, ix=0;
            for(int i=1; i<L-1; ++i) {
                p[i] = (i<ix)? min(p[(id<<1)-i], ix-i) : 0;
                while(T[i+p[i]+1]==T[i-p[i]-1]) ++p[i];
                if(i+p[i]>ix) { ix=i+p[i]; id=i; }
            }
            int offset=(int)(max_element(p+1,p+L-1)-p);
            int maxL=p[offset];
            delete[] p;
            return s.substr( (offset-1-maxL)>>1 , maxL);
        }
};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    Solution sol;
    cin>>s;
    cout<<sol.longestPalindrome(s)<<endl;
    return 0;
}
