#include <cstdio>
#include <assert.h>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;
const int M = 9901;

map<int,int> pd(int n) {
    map<int,int> r;
    for(int i=2; i*i<=n; ++i) {
        while(n%i==0) {
            ++r[i];
            n/=i;
        }
    }
    if(n!=1) r[n]=1;
    return r;
}

int fast_pow(int x, long long int n) {
    int res = 1%M;
    int base = x%M;
    n %= (long long int)(M-1);
    while(n>0L) {
        if (n&1L) {
            res = res * base % M;
        }
        base = base * base % M;
        n >>= 1L;
    }
    return res%M;
}

inline int inv_M(int a) {
    return fast_pow(a, M-2);
}

int summ(int a, int n) {
    if (n==0) return 1L;
    if (n%2L) { // 奇數
        return summ(a, n>>1L) * (1 + fast_pow(a, n/2+1)) % M;
    } 
    return (summ(a, (n>>1L)-1L) * (1 + fast_pow(a, n/2+1)) %M + fast_pow(a, n/2)) % M;
}

inline int cal(const int &a, const int &b, const int &n) {
    long long int p = (long long int)n * (long long int)b;
    int ar = fast_pow(a, p+1L);
    if (ar==1) return summ(a, p); // fails
    return ((ar - 1 + M)%M) * inv_M((a-1+M)%M) %M;
}

inline int solv(int A, int B) {
    int res=1;
    if (A==0) return 0;
    if (B==0) return 1;
    //A%=M;
    map<int, int> fac(pd(A));
    for (map<int,int>::iterator v=fac.begin(); v!=fac.end(); ++v) {
        //cout << v->first << ':' << v->second << endl;
        res = res * cal(v->first%M, v->second, B) % M;
    }

    return res;
}

int main(void) {
    int A, B;
    while(scanf("%d%d", &A, &B)==2) {
        printf("%d\n", solv(A,B));
    }
    return 0;
}
