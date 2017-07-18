#include <cstring>
#define __MAX(a,b) ((a)>(b)?(a):(b))

struct SegmentTree {
    enum{ MAXN=1000000, TREEND=3, TREENN=MAXN*TREEND};
    int seg[TREENN]; 
    int cl[MAXN+3];
    inline int n3(long long int n){
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

    inline void init() {
        memset(this->cl, 0x00, sizeof(this->cl[0])*MAXN);
        memset(this->seg,0x00, sizeof(this->seg[0])*TREENN);
        build(1, MAXN, 1);
    }
#undef IN_RANGE
#undef OO_RANGE
#undef LEFT
#undef RIGHT
};

#include <bits/stdc++.h>
using namespace std;

SegmentTree tree;

int main(void) {
    tree.init();
    int l, r;
    while(scanf("%d%d",&l,&r)==2) {
        int tl=l, tr=r;
        if(tl>tr) swap(tl,tr);
        printf("%d %d %d\n", l, r, tree.query(1, tree.MAXN, tl, tr, 1));
    }
    return 0;
}