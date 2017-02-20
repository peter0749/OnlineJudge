/*
// On Leet Code
// Difficulty: Medium
class Solution {
    public:
        string longestPalindrome(string s) {
            string odds, evens;
            //odd
            for(int i=0; i!=s.length(); ++i) {
                int j=1;
                for(; i-j>=0&&i+j<s.length()&&s[i-j]==s[i+j]; ++j);
                --j;
                if(j*2+1>=odds.length()) {
                    odds.clear();
                    odds.insert(odds.end(), s.begin()+i-j, s.begin()+i+j+1);
                }
            }
            //even
            for(int i=1; i<s.length(); ++i) {
                int l=i-1, r=i;
                for(; l>=0&&r<s.length()&&s[l]==s[r]; --l,++r);
                if(s[++l]==s[--r]&&r-l+1>=evens.length()) {
                    evens.clear();
                    evens.insert(evens.end(), s.begin()+l, s.begin()+r+1);
                }
            }
            return evens.length()>odds.length()?evens:odds;
        }
};

*/
#include <bits/stdc++.h>
using namespace std;

string lps(string &s) {
    string odds, evens;
    //odd
    for(int i=0; i!=s.length(); ++i) {
        int j=1;
        for(; i-j>=0&&i+j<s.length()&&s[i-j]==s[i+j]; ++j);
        --j;
        if(j*2+1>=odds.length()) {
            odds.clear();
            odds.insert(odds.end(), s.begin()+i-j, s.begin()+i+j+1);
        }
    }
    //even
    for(int i=1; i<s.length(); ++i) {
        int l=i-1, r=i;
        for(; l>=0&&r<s.length()&&s[l]==s[r]; --l,++r);
        if(s[++l]==s[--r]&&r-l+1>=evens.length()) {
            evens.clear();
            evens.insert(evens.end(), s.begin()+l, s.begin()+r+1);
        }
    }
    return evens.length()>odds.length()?evens:odds;
}

int main(void) {
    string input;
    cin>>input;
    cout<<lps(input)<<endl;
    return 0;
}
