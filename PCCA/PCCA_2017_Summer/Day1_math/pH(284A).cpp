#include <bits/stdc++.h>
using namespace std;

typedef long long int llt;

int main(void) {
    llt p;
    int counter=0;
    cin >> p;
    for (llt i=1; i<p; ++i) {
        bool succ=true;
        llt x=i;
        for (llt j=1; j<p-1; ++j) {
            if ((x-1LL)%p==0LL) {
                succ=false;
                break;
            }
            x=(x*i)%p;
        }
        counter += (succ&&(x-1)%p==0)?1LL:0LL;
    }
    cout << counter << endl;
    return 0;
}
