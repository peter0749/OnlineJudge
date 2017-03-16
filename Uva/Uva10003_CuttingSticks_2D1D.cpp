#include <bits/stdc++.h>
using namespace std;
vector<int> cutp;
const size_t MAXN(55);
const int LIM=1e9+7;
int dp[MAXN][MAXN];
int dp2[MAXN][MAXN]; //For opt 2D/1D

int cuts(int l, int r) {
    for(int i=r-2; i>=0; --i) {
        for(int j=i+2; j<=r; ++j) {
            int minv=LIM;
            int bestk=i+1;
            dp2[i][j-1]=(dp2[i][j-1]==-1?bestk:dp2[i][j-1]);
            dp2[i+1][j]=(dp2[i+1][j]==-1?j-1:dp2[i+1][j]);
            for(int k=dp2[i][j-1]; k<=dp2[i+1][j]; ++k) {
                int t=dp[i][k]+dp[k][j];
                if(t<minv) {
                    minv=t;
                    bestk=k;
                }
            }
            dp2[i][j] = bestk;
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
        for(int i=0;i<=n+1; ++i) for(int j=0; j<=n+1; ++j) {
            dp[i][j]=0, dp2[i][j]=-1;
        }
        cout<< "The minimum cutting is " << cuts(0,n+1) <<".\n";
    }
    return 0;
}
