#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main(void) {
    int n;
    char c[17];
    while(scanf("%d", &n)==1 ) {
        for (int i=0; i<(1<<n); ++i) {
            for (int j=0, k=(1<<(n-1)); j<n; ++j, k>>=1)
                c[j] = k&i?'1':'0';
            c[n] = '\n';
            write(1,c,n+1);
        }
    }
    return 0;
}
