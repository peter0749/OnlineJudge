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
using namespace std;

const size_t TREEND=4;
const size_t TREENN=MAXN*TREEND;
int  seg[TREENN]; // neg, pos
int lazy[TREENN];  // neg, pos

#define LEFT(i) ((i)<<1)
#define RIGHT(i) ((i)<<1|1)

template <class T>
inline T operationOnPull(const T &a, const T &b) {
    return a + b;
}

template <class T>
inline T operationOnPush(const T &a, const T &b) {
    return operationOnPull<T>(a , b);
}

inline void init(int n, int *seg, int *lazy) {
    n*=TREEND;
    memset(seg, 0x00, sizeof(seg[0])*(n+1));
    memset(lazy, 0x00, sizeof(lazy[0])*(n+1));
}

#define IN_RANGE (qL<=L && qR>=R)
#define OO_RANGE (L>qR || R<qL)

inline void _push(int lev, int seg[], int lazy[]) {
    if (!lazy[lev]) return;
    seg[LEFT(lev)] = operationOnPush<int>(seg[LEFT(lev)],  (lazy[LEFT(lev)] = lazy[lev])); 
    seg[RIGHT(lev)] = operationOnPush<int>(seg[RIGHT(lev)], (lazy[RIGHT(lev)] = lazy[lev])); 
    lazy[lev] = 0;
}

// 更新
inline void _pull(int lev, int seg[]) { 
    seg[lev] = operationOnPull<int>(seg[LEFT(lev)] , seg[RIGHT(lev)]);
}

void update(int L, int R, int qL, int qR, int lev, int op, int seg[], int lazy[]) { 
    if (OO_RANGE) return;
    int M = (L+R)>>1;
    if (IN_RANGE) {
        seg[lev] = operationOnPull<int>(seg[lev],op);
        lazy[lev] = op;
        return;
    }
    _push(lev, seg, lazy);
    update(L, M, qL, qR, LEFT(lev), op, seg, lazy);
    update(M+1, R, qL,qR, RIGHT(lev),op,seg, lazy);
    _pull(lev, seg);
}

int query(int L, int R, int qL, int qR, int flag, int seg[], int lazy[]) {
    int M=(L+R)>>1;
    if (OO_RANGE) return 0; // 沒東西
    if (IN_RANGE) return seg[flag];
    _push(flag, seg, lazy);
    int left=0, right=0;
    left = query(L,M,qL,qR,LEFT(flag),seg,lazy);
    right = query(M+1,R,qL,qR,RIGHT(flag),seg,lazy);
    return operationOnPull<int>(left, right);
}

int main(void){
    int term;
    char temp[4096];
    scanf("%d", &term);
    for (int cases=1; cases<=term; ++cases) {
        printf("Case %d:\n", cases);
        int n;
        scanf("%d", &n);
        init(n, seg, lazy);
        for (int i=1; i<=n; ++i) {
            int t;
            scanf("%d", &t);
            update(1, n, i, i, 1, t, seg, lazy);
        }
        while((fgets(temp, 4000, stdin) != NULL) && strncmp(temp, "End", 3)) {
            int l, r;
            if (strncmp(temp, "Query", 5)==0) {
                sscanf(temp+5, "%d %d", &l, &r);
                printf("%d\n", query(1,n,l,r,1,seg,lazy));
            } else if (strncmp(temp, "Add", 3)==0) {
                sscanf(temp+3, "%d %d", &l, &r);
                update(1,n,l,l,1,r,seg,lazy);
            } else if (strncmp(temp, "Sub", 3)==0) {
                sscanf(temp+3, "%d %d", &l, &r);
                update(1,n,l,l,1,-r,seg,lazy);
            }
        }
    }
    return 0;
}
