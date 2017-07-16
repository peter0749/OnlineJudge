#include <cstring>

struct SegmentTree {
    enum{ MAXN=101000, TREEND=4, TREENN=MAXN*TREEND};
    long long int  seg[TREENN]; // neg, pos
    long long int lazy[TREENN];  // neg, pos

//#define HALF_OPEN_INTERVAL
#define LEFT(i) ((i)<<1)
#define RIGHT(i) ((i)<<1|1)

    inline void init(int n) {
        using std::memset;
        n *= TREEND;
        memset(this->seg, 0x00, sizeof(this->seg[0])*(n+1));
        memset(this->lazy, 0x00, sizeof(this->lazy[0])*(n+1));
    }

#ifndef HALF_OPEN_INTERVAL
    // 節點紀錄閉區間   [, ]
#define IN_RANGE (qL<=L && qR>=R)
#define OO_RANGE (L>qR || R<qL)
#else
    // 節點紀錄半開區間 [, )
#define IN_RANGE (qL<=L && qR>=R)
#define OO_RANGE (L>=qR || R<=qL)
#endif

    inline void _push(int lev, int L, int M, int R) {
        if (lazy[lev]==0LL) return; // 有懶標記，我底下的子樹還沒更新
        if (L<=M) {
            lazy[LEFT(lev)] += lazy[lev];
            seg[LEFT(lev)] += lazy[lev]*((long long int)(M-L+1)); // 把懶標往下壓，左右子樹更新答案
        }
        if (R> M) {
            lazy[RIGHT(lev)] += lazy[lev];
            seg[RIGHT(lev)]+= lazy[lev]*((long long int)(R-M));
        }
        lazy[lev] = 0LL;
    }

    // 更新
    inline void _pull(int lev, int L, int M, int R) {
        seg[lev] = 0LL;
        if (L<=M)
            seg[lev] += seg[LEFT(lev)]; // 回傳更新後答案
        if (R> M)
            seg[lev] += seg[RIGHT(lev)];
    }

    void update(int L, int R, int qL, int qR, int lev, long long int op) {
        if (OO_RANGE) return;
        int M = (L+R)>>1;
        if (IN_RANGE) {
            lazy[lev] += op; // 懶標記
            seg[lev]  += op*(long long int)(R-L+1); // 更新現在的區間，底下子樹還沒更新
            return;
        }
        _push(lev, L, M, R);
        update(L, M, qL, qR, LEFT(lev), op);
#ifndef HALF_OPEN_INTERVAL
        update(M+1, R, qL,qR, RIGHT(lev),op);
#else
        update(M, R, qL,qR, RIGHT(lev),op);
#endif
        _pull(lev, L, M, R);
    }

    long long int query(int L, int R, int qL, int qR, int flag) {
        int M=(L+R)>>1;
        if (OO_RANGE) return 0LL; // 沒東西
        if (IN_RANGE) return seg[flag];
        _push(flag, L, M, R); // 查詢之前，必須保證這個節點底下的左右子樹是正確的
        long long int left = 0LL, right = 0LL;
        left = query(L,M,qL,qR,LEFT(flag));
#ifndef HALF_OPEN_INTERVAL
        right= query(M+1,R,qL,qR,RIGHT(flag));
#else
        right= query(M,R,qL,qR,RIGHT(flag));
#endif
        _pull(flag, L, M, R); // if update (optional)
        return left+right; // if update (optional)
        //return operationOnPull<int>(left, right); // not update
    }
#undef IN_RANGE
#undef OO_RANGE
#undef LEFT
#undef RIGHT
#undef HALF_OPEN_INTERVAL
};

#include <iostream>
#include <cassert>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    SegmentTree *T=NULL;
    T = new SegmentTree;
    assert(T!=NULL);
    SegmentTree &tree = *T;
    tree.init(N);
    for (int i=1; i<=N; ++i) {
        long long int input;
        cin >> input;
        tree.update(1, N, i, i, 1, input);
    }
    while(Q--) {
        char op;
        int l, r;
        long long int x;
        cin >> op >> l >> r;
        switch (op) {
            case 'C': {
                    cin >> x;
                    tree.update(1, N, l, r, 1, x);
                }
                break;
            case 'Q': {
                    cout << tree.query(1, N, l, r, 1) << '\n';
                }
                break;
        }
    }
    delete T;
    return 0;
}
