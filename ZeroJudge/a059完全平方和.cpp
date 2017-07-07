#include <bits/stdc++.h>
using namespace std;

const size_t MAXN = 1010;
int prefix[MAXN]; // 0 by default

inline int query(int a, int b) { // [a,b]
    return prefix[b] - prefix[a-1]; // 1-base -> 0-base
}

int main(void) {
    int T;
    for (int i=1; i*i<MAXN; ++i) {
        prefix[i*i] = i*i;
    }
    for (int i=1; i<MAXN; ++i) prefix[i] += prefix[i-1];
    scanf("%d", &T);
    for (int i=1; i<=T; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l>r) swap(l,r);
        printf("Case %d: %d\n", i, query(l,r));
    }
    return 0;
}
