#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

const size_t MAXN=100005;
const int P=1e9+7;
int dp[MAXN]; // result 

inline void mk_table(const int k) {
    fill(&dp[0], &dp[0]+k, 1);  // [0,k-1]
    dp[k] = 2; dp[0]=0; // k, 0
    for (int i=k+1; i<MAXN; ++i) { // length
        dp[i] = (dp[i-1]+dp[i-k])%P;
    }
    for (int i=1; i<MAXN; ++i) {
        dp[i]=(dp[i]+dp[i-1])%P;
    }
}

inline int query(const int a, const int b) {
    return (dp[b] - dp[a-1]+P)%P;
}

int main(void) {
    int T, K, a, b;

    scanf("%d%d", &T, &K);
    mk_table(K);
    while(T-- > 0) { // T approachs to 0 OuO
        scanf("%d%d",&a,&b);
        printf("%d\n", query(a,b));
    }
    return 0;
}
