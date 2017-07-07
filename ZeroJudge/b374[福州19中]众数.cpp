#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
using namespace std;

int N, M;
int YEE[30005];

int main(void) {
    int N;
    int mx=-1e9,mn=1e9;
    int maxn = 0;
    scanf("%d", &N);
    memset(YEE, 0x00, sizeof(YEE));
    for (int i=0; i<N; ++i) {
        int t;
        scanf("%d", &t);
        ++YEE[t];
        mx=max(mx,t);
        mn=min(mn,t);
    }
    for (int i=mn; i<=mx; ++i) maxn = max(maxn, YEE[i]);
    for (int i=mn; i<=mx; ++i) {
        if (YEE[i]==maxn) printf("%d %d\n", i, maxn);
    }

    return 0;
}
