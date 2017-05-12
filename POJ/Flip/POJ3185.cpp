#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

int seg[30], flip[30];

void init(void) {
    for (int i=0; i<20; ++i) cin >> seg[i];
    seg[20]=0;
}

inline int check(const int k) {
    return ( seg[k] + flip[k] + ((k-1>=0)?flip[k-1]:0)  )&1u;
}

int tryFlip(int c) {
    int ret;
    memset(flip,0x00,sizeof(flip));
    ret=flip[0]=c;
    for (int i=1; i<20; ++i) { // it is guaranteed that we can always find a solution for the input.
        if (check(i-1)) { 
            flip[i]=1;
            ++ret;
        }
    }
    return ret;
}

void solv(void) {
    int res = min(tryFlip(0), tryFlip(1));
    cout << res << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    solv();
    return 0;
}
