#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#define _DEBUG
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>
#define MAXN 100010
#define MAXT 33
using namespace std;

const size_t TREENN=MAXN*3;
int  seg[TREENN];
int lazy[TREENN]; 

inline void init(void) {
    memset(seg, 0x00, sizeof(seg));
    memset(lazy, 0x00, sizeof(lazy));
}

#ifdef DEBUG
inline void print_bit(int n) {
    for (int i=MAXT; i>=0; --i) printf("%d", (n>>i)&1);
}
#endif

#define IN_RANGE (qL<=L && qR>=R)
#define OO_RANGE (L>qR || R<qL)

inline void _push(int lev, int seg[], int lazy[]) {
    if (!lazy[lev]) return;
    seg[lev<<1] = lazy[lev<<1] = lazy[lev]; 
    seg[lev<<1|1] = lazy[(lev<<1)|1] = lazy[lev]; 
    lazy[lev] = 0;
}

// 更新
inline void _pull(int lev, int seg[]) { seg[lev] = seg[lev<<1] | seg[(lev<<1)|1]; }

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
    if (OO_RANGE) return 0; // 沒東西
    if (IN_RANGE) return seg[flag];
    _push(flag, seg, lazy);
    int left=0, right=0;
    left = query(L,M,qL,qR,flag<<1,seg,lazy);
    right = query(M+1,R,qL,qR,flag<<1|1,seg,lazy);
    return left | right;
}

#define RL() fgets(temp, 4000, stdin)
#ifdef DEBUG
#define CHECK()  \
    for (int _NOTE=1; _NOTE<TREENN; ++_NOTE) { printf("%03d: ", _NOTE); print_bit(seg[_NOTE]); putchar(' '); print_bit(lazy[_NOTE]); putchar('\n'); }
#else
#define CHECK()   
#endif

int main(void){
    init();
    char temp[128];
    int L, T, O;
    RL();
    sscanf(temp,"%d%d%d", &L, &T, &O);
    update(1, L, 1, L, 1, 2, seg, lazy);
    CHECK();
    for (int i=0; i<O; ++i) {
        int a, b, c;
        char op;
        RL();
        sscanf(temp, "%1c %d %d %d", &op, &a, &b, &c);
        if (a>b) swap(a,b);
        switch(op) {
            case 'C':
                update(1,L,a,b,1,1<<c, seg, lazy);
                CHECK();
                break;
            case 'P':
                int res = query(1, L, a, b, 1, seg, lazy)&(-2);
                int sum = 0;
                while(res) { sum += (res&1); res>>=1; }
                CHECK();
                printf("%d\n", sum);
                break;
        }
    }
    return 0;
}
