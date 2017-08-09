#include <bits/stdc++.h>
using namespace std;

long long T, n, x, y;

int main(void) {
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) {
        cin >> n >> x >> y;
        long long tot = 0;
        for (int i=2; i<=n; ++i) {
            tot += (long long)(n-i+1)*(n-i+1)*(i-1);
        }
        long long w=0, h=0;
        w = max(x-1,n-x);
        h = max(y-1,n-y);
        long long s = max(w,h);
#define IN() (tx>=1L&&ty>=1L&&tx+i<=n&&ty+i<=n)
        for (int i=1; i<=s; ++i) {
            int tx=x-i;
            int ty=y-i;
            if (IN()) --tot;
            for (int j=0; j<i; j++) {
                ++tx; if(IN()) --tot;
            }
            for (int j=0; j<i; ++j) {
                ++ty; if(IN()) --tot;
            }
            for (int j=0; j<i; ++j) {
                --tx; if(IN()) --tot;
            }
            for (int j=1; j<i; ++j) {
                --ty; if(IN()) --tot;
            }
        }
        cout << tot << '\n';
    }
    return 0;
}
