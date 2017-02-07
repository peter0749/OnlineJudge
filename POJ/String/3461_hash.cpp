#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define STRL 1000010
using namespace std;
typedef unsigned long long int UT;
string str, pat;
const UT hsaBase = 37, MOD1d7=1000000007;
UT hsaPow, hsaS, hsaP;

UT gethash(string &S) {
    UT h=0;
    for(string::size_type i=0; i!=pat.length(); ++i ) {
        h = (h * hsaBase  ) % MOD1d7;
        h = (h + (UT)S[i]) % MOD1d7;
    }
    return h;
}

int solv() {
    if(pat.length()>str.length()) return 0;
    hsaPow = 1uLL;
    unsigned int pol = pat.length()-1; //highest power
    UT temp = hsaBase;
    //Initialize fast-pow
    while(pol) {
        if(pol&1) hsaPow = (hsaPow*temp) % MOD1d7;
        temp = (temp * temp) % MOD1d7;
        pol>>=1;
    }
    hsaS = gethash(str); hsaP = gethash(pat);
    int ans = 0;
    for(string::size_type i=0 ;; ++i) {
        if(hsaS==hsaP) ++ans;
        if(i+pat.length()==str.length()) break; //Warn
        hsaS = (hsaS-((UT)str[i]*hsaPow)%MOD1d7+MOD1d7) % MOD1d7;
        hsaS = ( (hsaS*hsaBase)%MOD1d7 + (UT)str[i+pat.length()] ) % MOD1d7;
    }
    return ans;
}

int main(void) {
    ios::sync_with_stdio(false);cin.tie(0);
    int T;
    cin >> T;
    while(T-- ) {
        cin >> pat >> str;
        cout << solv() << '\n';
    }
    return 0;
}
