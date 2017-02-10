#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ULL;
const int MAXN=500;
int sg[MAXN]={0,1,2,3,1};
set<int> s, l, t;
ULL input[10010];

void build(){
    l.insert(3);l.insert(2);
    for(int i=5; i<MAXN; ++i) {
        s.clear();
        for(int j=i-1, k=0; k<=j; --j, ++k) {
            //cout << "dbg: " << j << ' ' << k << endl;
            //int t;
            //cin>>t;
            s.insert(sg[j]^sg[k]);
        }
        t=s;
        s.insert(l.begin(), l.end());
        l=t;
        int maxval = *s.rbegin();
        int j;
        for(j=0; j<=maxval && s.count(j); ++j);
        sg[i]=j;
    }
}

int getsg(ULL n) {
    if(n>=200uLL) return sg[200uLL+(n-200uLL)%12uLL];
    return sg[n];//n<200
}

int main(void) {
    ios::sync_with_stdio(false);cin.tie(0);
    int T, n;
    build();
    cin >> T;
    while(T--) {
        cin >> n;
        ULL ans=0uLL;
        for(int i=0; i<n; ++i) {
            ULL temp;
            cin >> temp;
            ans^=getsg(temp);
        }
        cout<<(ans?'F':'S')<<'\n';
    }
    
    return 0;
}
