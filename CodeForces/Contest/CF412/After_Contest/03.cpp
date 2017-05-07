#include <bits/stdc++.h>
using namespace std;

long long int x,y,p,q;
const  long long int Inf=(1<<30);

inline bool check(long long int m) {
    return ((q*m)-y>=(p*m)-x && (p*m)-x>=0);
}

void solv() {
    // binary-search
    if ( !check(Inf) ) {
        cout << "-1" << endl;
        return;
    }
    long long int l=0, r=Inf, m, res;
    while(r-l>1) {
        m = (r+l)>>1;
        if (check(m)) r=m;
        else l=m;
    }
    res = r*q-y;
    cout << res << endl;
}

int main(void) {
    int t;
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> x >> y >> p >> q;
        solv();
    }
    return 0;
}
