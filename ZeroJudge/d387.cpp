#pragma GCC target ("avx")
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

const size_t MAXN=1000003;
bool isPrime[MAXN];

inline void mk_prime(void) {
    fill(isPrime, isPrime+MAXN, true);
    for (int i=3; i<MAXN; i+=2) {
        if (isPrime[i]) {
            for (int j=i+i; j<MAXN; j+=i)
                isPrime[j]=false;
        }
    }
}

inline bool is_prime(unsigned int n) {
    return n==2?true:(n&1?isPrime[n]:false);
}

inline unsigned int palidrome(unsigned int n) {
    unsigned int tmp=0;
    while(n>0) {
        tmp = tmp*10 + n%10;
        n/=10;
    }
    return tmp;
}

inline void solv(unsigned int n) {
    if (is_prime(n)) {
        unsigned int pn = palidrome(n);
        if (n!=pn && is_prime(pn)) // 不存在 xxx0, 0xxx 的組合（不是質數）
            printf("%u is emirp.\n",n);
        else
            printf("%u is prime.\n",n);
    } else {
        printf("%u is not prime.\n",n);
    }
}

int main(void) {
    unsigned int n;
    mk_prime();
    while(scanf("%u",&n)==1) {
        solv(n);
    }

    return 0;
}
