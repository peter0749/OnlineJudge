#include <bits/stdc++.h>
using namespace std;

int main(void) {
    // ios::sync_with_stdio(false); cin.tie(0);
    int a, b, c, n;
    int counter=0;
    cin >> a >> b >> c >> n;
    if (b>c) swap(b,c);
    for (int i=0; i<n; ++i) {
        int temp; cin >> temp;
        if(temp>b&&temp<c) ++counter;
    }
    cout << counter << '\n';
    return 0;
}
