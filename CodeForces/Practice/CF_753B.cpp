#include <bits/stdc++.h>
#define MAXL 4
using namespace std;

int stk[MAXL]={0};

int main(void){
    int a, b, top;
    top = 0;
    for(int i=0; i<10; ++i){
        printf("%d%d%d%d\n", i,i,i,i);
        fflush(stdout);
        scanf("%d%d", &a, &b);
        if(a||b) {
            stk[top++] = i;
        }
    }
    do{
        for( register int i=0; i<MAXL; ++i) printf("%d",stk[i]);
        putchar('\n');
        fflush(stdout);
    } while(scanf("%d%d",&a,&b)==2 && a!=4 && next_permutation(stk, stk+MAXL));
    return 0;
}
