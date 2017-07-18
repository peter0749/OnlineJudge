#include <string.h>
#define __MAX(a,b) ((a)>(b)?(a):(b))

#define MAXN 1000000
#define TREEND 3
#define TREENN MAXN*TREEND
int seg[TREENN]; 
int cl[MAXN+3];
int n3(long long int n){
    return n==1?1:(n<MAXN&&cl[n]?cl[n]:n<MAXN?cl[n]=(n&1LL?n3(3*n+1):n3(n>>1))+1:(n&1LL?n3(3*n+1):n3(n>>1))+1);
}

#define LEFT(i) ((i)<<1)
#define RIGHT(i) ((i)<<1|1)
#define IN_RANGE (qL<=L && qR>=R)
#define OO_RANGE (L>qR || R<qL)

void build(int L, int R, int lev) {
    if (L==R) {
        seg[lev] = n3(L);
        return;
    }
    int M = (L+R)>>1;
    if (L<=M)
        build(L, M, LEFT(lev));
    if (M <R)
        build(M+1, R, RIGHT(lev));
    seg[lev] = __MAX(seg[LEFT(lev)] , seg[RIGHT(lev)]);
}

int query(int L, int R, int qL, int qR, int flag) {
    if (IN_RANGE) return seg[flag];
    int M=(L+R)>>1;
    int left=0, right=0;
    if (qL<=M)
        left = query(L,M,qL,qR,LEFT(flag));
    if (M <qR) 
        right = query(M+1,R,qL,qR,RIGHT(flag));
    return __MAX(left,right); 
}

void init() {
    memset(cl, 0x00, sizeof(cl[0])*MAXN);
    memset(seg,0x00, sizeof(seg[0])*TREENN);
    build(1, MAXN, 1);
}
#undef IN_RANGE
#undef OO_RANGE
#undef LEFT
#undef RIGHT

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    init();
    int l, r;
    while(scanf("%d%d",&l,&r)==2) {
        int tl=l, tr=r;
        if(tl>tr) tl^=tr^=tl^=tr;
        printf("%d %d %d\n", l, r, query(1, MAXN, tl, tr, 1));
    }
    return 0;
}
