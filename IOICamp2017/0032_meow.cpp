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
        bool fail=false;
        for(int i=0; i<k && i<N; ++i) {
            if(S.count(V[i])) { // Fails at the beginning.
                fail=true; break;
            }
            S.insert(V[i]);
        }
        int i;
        if(!fail) {
            for(i=k; i<N; ++i) {
                if(S.count(V[i])) break;
                //else
                S.erase(V[i-k]);
                S.insert(V[i]);
            }
            fail = (i!=N);
        }
        cout << (!fail?"Yes\n":"No\n");
        V.clear(); S.clear();
    }
    return 0;
}
