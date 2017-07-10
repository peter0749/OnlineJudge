#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#define _DEBUG
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#define MAXN 50010
#define MAXT 2
using namespace std;

const size_t TREENN=MAXN*3;
int  seg[MAXT][TREENN]; // neg, pos
int lazy[MAXT][TREENN];  // neg, pos

inline void init(void) {
    memset(seg, 0x00, sizeof(seg));
    memset(lazy, 0x00, sizeof(lazy));
}

#define IN_RANGE (qL<=L && qR>=R)
#define OO_RANGE (L>qR || R<qL)

inline void _push(int lev, int seg[], int lazy[]) {
    if (!lazy[lev]) return;
    seg[lev<<1] = lazy[lev<<1] = lazy[lev]; 
    seg[lev<<1|1] = lazy[(lev<<1)|1] = lazy[lev]; 
    lazy[lev] = 0;
}

// 更新
inline void _pull(int lev, int seg[]) { seg[lev] = max( seg[lev<<1] ,seg[(lev<<1)|1] ); }

void update(int L, int R, int qL, int qR, int lev, int op, int seg[], int lazy[]) { 
    if (OO_RANGE) return;
    int M = (L+R)>>1;
    if (IN_RANGE) {
        seg[lev] = op;
        lazy[lev] = op;
        return;
    }
    _push(lev, seg, lazy);
    update(L, M, qL, qR, lev<<1, op, seg, lazy);
    update(M+1, R, qL,qR, lev<<1|1,op,seg, lazy);
    _pull(lev, seg);
}

int query(int L, int R, int qL, int qR, int flag, int seg[], int lazy[]) {
    int M=(L+R)>>1;
    if (OO_RANGE) return INT_MIN; // 沒東西
    if (IN_RANGE) return seg[flag];
    _push(flag, seg, lazy);
    int left=0, right=0;
    left = query(L,M,qL,qR,flag<<1,seg,lazy);
    right = query(M+1,R,qL,qR,flag<<1|1,seg,lazy);
    return max( left , right );
}

#define RL() fgets(temp, 4000, stdin)

int main(void){
    init();
    int N, Q;
    scanf("%d%d",&N, &Q);
    for (int i=1; i<=N; ++i) {
        int h; scanf("%d",&h);
        update(1,N,i,i,1,h,seg[1],lazy[1]);
        update(1,N,i,i,1,-h,seg[0],lazy[0]);
    }
    while(Q--) {
        int l,r ;
        scanf("%d%d", &l, &r);
        if(l>r) swap(l,r);
        printf("%d\n", query(1,N,l,r,1,seg[1],lazy[1]) + query(1,N,l,r,1,seg[0],lazy[0]));
    }
    return 0;
}
