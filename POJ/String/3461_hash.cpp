#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define STRL 1000010
#define PURGE(X) sscanf( (X) , "%s" , (X) )
using namespace std;
typedef unsigned long long int UT;
char str[STRL], pat[STRL];
const UT hsaBase = 37, MOD1d7=1000000007;
UT hsaPow, hsaS, hsaP;

UT gethash(char *S, int len) {
    UT h=0;
    for(int i=0; i!=len; ++i ) {
        h = (h * hsaBase  ) % MOD1d7;
        h = (h + (UT)S[i]) % MOD1d7;
    }
    return h;
}

int solv() {
    int plen=strlen(pat);
    int slen=strlen(str);
    if(plen>slen) return 0;
    hsaPow = 1uLL;
    unsigned int pol = plen-1; //highest power
    UT temp = hsaBase;
    //Initialize fast-pow
    while(pol) {
        if(pol&1) hsaPow = (hsaPow*temp) % MOD1d7;
        temp = (temp * temp) % MOD1d7;
        pol>>=1;
    }
    hsaS = gethash(str, plen); hsaP = gethash(pat, plen);
    int ans = 0;
    for(int i=0 ;; ++i) {
        if(hsaS==hsaP) ++ans;
        if(i+plen==slen) break; //Warn
        hsaS = (hsaS-((UT)str[i]*hsaPow)%MOD1d7+MOD1d7) % MOD1d7;
        hsaS = ( (hsaS*hsaBase)%MOD1d7 + (UT)str[i+plen] ) % MOD1d7;
    }
    return ans;
}

int main(void) {
    int T;
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d", &T);
    while(T-- ) {
        fgets(pat, sizeof(pat), stdin);
        fgets(str, sizeof(str), stdin);
        PURGE(pat);
        PURGE(str);
        printf("%d\n",solv());
    }
    return 0;
}
