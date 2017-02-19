#include <bits/stdc++.h>
using namespace std;

inline void rxd(vector<unsigned int> &arr) {
    unsigned int maxv = *max_element(arr.begin(), arr.end());
    if(maxv==0) return;
    maxv = 32-__builtin_clz(maxv);
    vector<unsigned int> bucket[2];
    for(unsigned int d=0; d<maxv; ++d) {
        bucket[0].clear(); bucket[1].clear();
        for(vector<unsigned int>::iterator i=arr.begin();\
            i!=arr.end(); ++i) {
            bucket[ ((*i)>>d)&1u ].push_back(*i);
        }
        arr.clear();
        #define UPDATE(X,Y) \
            X.insert( X.end(), Y.begin(), Y.end())
        UPDATE(arr, bucket[0]);
        UPDATE(arr, bucket[1]);
    }
}

vector<unsigned int> arr;

int main(void) {
    ios::sync_with_stdio(false);cin.tie(0);
    int N;
    while(cin>>N) {
        for(int i=0; i<N; ++i) {
            unsigned int temp; cin>>temp;
            arr.push_back(temp);
        }
        rxd(arr);
        vector<unsigned int>::iterator i=arr.begin();
        cout<<*i;
        for(++i; i!=arr.end(); ++i) cout<<' '<<*i;
        cout<<'\n';
        arr.clear();
    }
    return 0;
}
