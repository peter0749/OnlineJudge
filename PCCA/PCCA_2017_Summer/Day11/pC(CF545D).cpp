#include <bits/stdc++.h>
using namespace std;

vector<unsigned long long int> data;

int main(void) {
    int n ; cin>>n;
    for (int i=0; i<n; ++i) {
        unsigned long long int t; cin >> t;
        data.push_back(t);
    }
    sort(data.begin(), data.end());
    unsigned long long int sum=0LL;
    int dissapoint=0;
    for (const unsigned long long int &v: data) {
        if (sum>v) ++dissapoint;
        else sum+=v;
    }
    cout << (data.size()-dissapoint) << endl;
    return 0;
}