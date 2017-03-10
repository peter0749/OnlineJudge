#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstdlib>
using namespace std;

typedef long long int UT;
const size_t MAXN=100000;
vector<int>plist;
bool is_prime[MAXN];

void mk_prime() {
    fill(is_prime, is_prime+MAXN, true);
    is_prime[1]=is_prime[0]=false;
    plist.push_back(2);
    for(int i=3; i<MAXN; i+=2) {
        if(is_prime[i]) {
            plist.push_back(i);
            for(int j=i+i; j<MAXN; j+=i) is_prime[j]=false;
        }
    }
}

inline bool is_p(int n) {
    if(n==2) return true;
    if(n%2==0) return false;
    if(n<MAXN) return is_prime[n];
    for(vector<int>::iterator v=plist.begin(); v!=plist.end() && (*v)*(*v)<=n; ++v) {
        if(n%(*v)==0) return false;
    }
    return true;
}

bool fastpow(UT a, UT p) {
    if(is_p(p)) return false;
    UT P=p;
    UT t=a, res=1uLL;
    while(p>0uLL) {
        if(p&1uLL) {
            res = (res*t)%P;
        }
        t=(t*t)%P;
        p>>=1uLL;
    }
    return res%P==a;
}

int main(void) {
    UT a,p;
    mk_prime();
    while(scanf("%lld%lld",&p,&a)==2 ) {
        if(p==0uLL&&a==0uLL)break;
        printf(fastpow(a,p)?"yes\n":"no\n");
    }
    return 0;
}
