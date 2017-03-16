#include <bits/stdc++.h>
using namespace std;
vector<int> cutp;
const size_t MAXN(60);
const int LIM=1e9+7;
int dp[MAXN][MAXN];

int cuts(int l, int r) {
    for(int i=r-2; i>=0; --i) {
        for(int j=i+2; j<=r; ++j) {
            int minv=LIM;
            for(int k=i+1; k<j; ++k) {
                minv=min(minv,dp[i][k]+dp[k][j]);
            }
            dp[i][j]=cutp.at(j)-cutp.at(i)+minv;
        }
    }
    return dp[l][r];
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
        for(int i=0; i<=n+1; ++i) for(int j=0; j<=n+1; ++j) dp[i][j]=0;
        cout<< "The minimum cutting is " << cuts(0,n+1) <<".\n";
    }
    return 0;
}
