#include <bits/stdc++.h>
using namespace std;

int main(void ) {
    ios::sync_with_stdio(false);
    int T, n, m, r, c;
    int arr[5], test;
    cin>>T;
    while(T--) {
        cin>>m>>n>>r>>c;
        arr[0] = r;
        arr[1] = c;
        arr[2] = m-r-1;
        arr[3] = n-c-1;
        test = 0;
        for(int i=0;i<4; ++i) test ^= (arr[i]);
        cout<< (test?"Gretel":"Hansel") << '\n';
    }
    return 0;
}
