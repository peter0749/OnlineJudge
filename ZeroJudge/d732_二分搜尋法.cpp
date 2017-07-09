#include <bits/stdc++.h>
using namespace std;

vector<int> data;

int main(void) {
    int n, q;
    while(scanf("%d%d", &n, &q)==2) {
        data.clear();
        for (int i=0; i<n; ++i) {
            int t;
            scanf("%d",&t);
            data.push_back(t);
        }
        for (int i=0; i<q; ++i) {
            int query;
            scanf("%d", &query);
            vector<int>::iterator v = lower_bound(data.begin(), data.end(), query);
            printf("%d\n", (v==data.end()||(*v)!=query)?0:(v-data.begin()+1));
        }
    }
    return 0;
}
