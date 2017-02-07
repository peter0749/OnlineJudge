#include <bits/stdc++.h>
using namespace std;

set<int> S;
vector<int> V;

int main(void) {
    int T, N, k;
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    while(T--) {
        cin >> N >> k;
        for(int i=0; i<N; ++i) {
            int temp;
            cin>>temp;
            V.push_back(temp);
        }
        for(int i=0; i<k && i<N; ++i) S.insert(V[i]);
        int i;
        for(i=k; i<N; ++i) {
            if(S.count(V[i])) break;
            //else
            S.erase(V[i-k]);
            S.insert(V[i]);
        }
        cout << (i==N?"Yes\n":"No\n");
        V.clear(); S.clear();
    }
    return 0;
}
