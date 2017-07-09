#include <bits/stdc++.h>
using namespace std;

int numofb[200];

int N, K; // col, ball

int main(void) {
    memset(numofb, 0x00 ,sizeof(numofb));
    cin >> K >> N;
    for (int i=0; i<K; ++i) {
        int t;
        cin >> t;
        ++numofb[t];
    }
    int EQ = K/N;
    int sum = 0;
    for (int i=1; i<=N; ++i) {
        sum += abs(numofb[i]-EQ);
    }
    cout << sum/2 << endl;
    return 0;
}
