#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a, b;
    while(scanf("%d%d", &a, &b)==2) {
        --a;
        printf("%d\n", (b/2+(b>=0)) - (a/2+(a>=0)) );
    }
    return 0;
}
