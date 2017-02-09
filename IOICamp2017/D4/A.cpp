#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);cin.tie(0);
    int T, n;
    cin>>T;
    while(T--) {
        cin>>n;
        if(n<=3 || n>=5) cout<<1<<'\n';
        else cout<<-1<<'\n';
    }
    return 0;
}
