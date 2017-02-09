#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);cin.tie(0);
    int T, n;
    cin>>T;
    while(T--) {
        cin>>n;
        cout<<(n&1?"tsan\n":"hao\n");
    }
    return 0;
}
