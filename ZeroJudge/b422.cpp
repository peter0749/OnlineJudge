#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int w,h;
    cin >> w >> h;
    cout << w << ' ' << h << '\n';
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            int r,g,b;
            cin >> r >> g >> b;
            if (j!=0) cout << ' ';
            int gray = (r+g+b+1)/3;
            cout << gray << ' ' << gray << ' ' << gray;
        }
        cout << endl;
    }
    return 0;
}
