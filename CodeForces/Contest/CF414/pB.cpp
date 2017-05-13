#include <bits/stdc++.h>
using namespace std;

int main(void) {
    long double h;
    int n;
    cin >> n >> h;
    for (int i=1; i<n; ++i) {
        long double temp = (double)n/(double)i;
        long double res = h/sqrtl(temp);
        cout << fixed << setprecision(12) << res << (i==n-1?'\n':' ');
    }
    return 0;
}
