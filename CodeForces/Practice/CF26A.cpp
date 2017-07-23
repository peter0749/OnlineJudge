#include <bits/stdc++.h>
using namespace std;

int table[4000];

int main(void) {
    int n, counter=0;
    cin >> n;
    fill(&table[0], &table[0]+n+2,0);
    for (int i=2; i<=n; ++i) {
        if (!table[i]) {
            for (int j=i+i; j<=n; j+=i) {
                ++table[j];
            }
        }
    }
    for (int i=2; i<=n; ++i) counter+=(table[i]==2)?1:0;
    
    cout << counter << endl;
    return 0;
}
