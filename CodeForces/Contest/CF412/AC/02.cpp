#include <bits/stdc++.h>
using namespace std;
int seqs[100];
int p, x, y;

bool init(int s, int val) {
    const int p = 475;
    int i = (s/50)%p;
    for (int j=0; j<25; ++j) {
        i = (i*96+42)%p;
        if (val==26+i) return true;
    }
    return false;
}

int solv() {
    int i, j;
    for (i=x; i>=y; i-=50) if( init(i, p) ) return 0;
    for (i=x,j=0 ;; i+=50, ++j) if( init(i,p) ) break;
    return (j+1)/2;
}

int main(void) {
    cin >> p >> x >> y;
    cout << solv() << endl;
    return 0;
}
