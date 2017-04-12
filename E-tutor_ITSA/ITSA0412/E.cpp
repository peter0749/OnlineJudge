#include <bits/stdc++.h>
using namespace std;

vector<long long int> data;
int main(void) {
    ios::sync_with_stdio(false);cin.tie(0);
    int N;
    cin >> N;
    while (N--) {
        int n;
        data.clear();
        cin >> n;
        for (int i=0; i<n; ++i) {
            long long int inp; cin>>inp;
            data.push_back(inp);
        }
        long long int sum=0;
        for (int i=0; i<n; ++i) {
            sum = sum*2 + data[i];
        }
        cout << sum << '\n';
    }
    return 0;
}
