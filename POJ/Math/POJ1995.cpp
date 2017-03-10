#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstdlib>
using namespace std;

typedef long long int UT;

UT fastpow(UT a, UT p, UT P) {
    UT t=a, res=1uLL;
    while(p>0uLL) {
        if(p&1uLL) {
            res = (res*t)%P;
        }
        t=(t*t)%P;
        p>>=1uLL;
    }
    return res%P;
}

int main(void) {
    UT a,p,K,M;
    int N, n;
    scanf("%d",&N);
    while(N--) {
        scanf("%lld",&M);
        scanf("%d",&n);
        UT ans=0;
        for(int i=0; i<n; ++i) {
            scanf("%lld%lld",&a,&K);
            ans += (fastpow(a,K,M)%M);
        }
        printf("%lld\n",ans%M);
    }
    
    return 0;
}
