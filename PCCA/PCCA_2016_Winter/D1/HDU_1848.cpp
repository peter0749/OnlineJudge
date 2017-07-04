#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 1010
using namespace std;
int fib[16];
int G[MAXN];

void create_fib(){
    fib[0]=1;
    fib[1]=1;
    for(int i=2; i<16; ++i) {
        fib[i] = fib[i-1]+fib[i-2];
    }
}

int X[5];

int main(void) {
    int max_x, g, x;
    set<int> s;
    create_fib();
    while(scanf("%d%d%d",X,X+1,X+2)==3 && X[0] ) {
        memset(G,0x00,sizeof(G));
        G[0] = 0;
        max_x = *max_element(X, X+3);
        for(int j=1; j<=max_x; ++j) {
            s.clear();
            for(int i=1; i<16; ++i) {
                if(fib[i]<=j) s.insert(G[j-fib[i]]);
            }
            g=0;
            while(s.count(g)!=0) ++g;
            G[j] = g;
        }
        x=0;
        for(int i=0; i<3; ++i) {
            x^=G[X[i]];
        }
        puts(x?"Fibo":"Nacci");
    }
    return 0;
}

