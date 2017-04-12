#include <bits/stdc++.h>
using namespace std;

vector<int>W, V;
int DP[200];
int res;

int sol(int n, int maxv) {
    memset(DP,0x00,sizeof(DP));
    for (int i=0; i<=maxv; ++i) {
        for (int j=0; j<n; ++j) {
            DP[i] = i-W[j]<0?DP[i]:max(DP[i],DP[i-W[j]]+V[j]);
        }
    }
    return DP[maxv];
}

int main(void) {
    //ios::sync_with_stdio(false);cin.tie(0);
    int N;
    cin >> N;
    while(N--) {
        int maxv, n;
        cin >> maxv;
        cin >> n;
        W.clear(); V.clear();
        for (int i=0; i<n; ++i) {
            int w, v;
            string str;
            cin >> w >> v >> str;
            W.push_back(w); V.push_back(v);
        }
        res = sol(n,maxv);
        cout << "Total: " << res << endl;
    }
    return 0;
}
