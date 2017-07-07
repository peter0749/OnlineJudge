#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > data;

int main(void) {
    //ios::sync_with_stdio(false);
    int N, M;
    vector<int> temp;
    while(scanf("%d%d",&N,&M)==2) {
        data.clear();
        for (int i=0; i<N; ++i) {
            temp.clear();
            for (int j=0; j<M; ++j) {
                int t; cin >> t;
                temp.push_back(t);
            }
            data.push_back(temp);
        }
        sort(data.begin(), data.end());
        for (const auto &u : data) {
            bool rbegin = true;
            for (const auto &v : u) {
                if(!rbegin) cout << ' ';
                cout << v;
                rbegin = false;
            }
            cout << endl;
        }
    }
    return 0;
}
