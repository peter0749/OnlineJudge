#include <bits/stdc++.h>
using namespace std;
vector<int> cutp;
const size_t MAXN(60);
const int LIM=1e9+7;
int dp[MAXN][MAXN];

int cuts(int l, int r) {
    if(r-l<=1) return 0; //no cut required
    if(dp[l][r]!=-1) return dp[l][r];
    int cost=cutp.at(r)-cutp.at(l);
    int minv=LIM;
    for(int i=l+1; i<r; ++i) {
        int t = cuts(l,i)+cuts(i,r);
        minv=min(minv, t);
    }
    cost+=minv;
    return dp[l][r]=cost;
}

int main(void) {
    ios::sync_with_stdio(false);cin.tie(0);
    int n, l;
    while(cin>>l&&l) {
        cutp.clear();
        cin>>n;
        cutp.push_back(0);
        for(int i=0; i<n; ++i) {
            int t; cin>>t;
            cutp.push_back(t);
        }
        cutp.push_back(l);
        int ans=LIM;
        for(int i=0; i<=n+1; ++i) for(int j=0; j<=n+1; ++j) dp[i][j]=-1;
        cout<< "The minimum cutting is " << cuts(0,n+1) <<".\n";
    }
    return 0;
}
