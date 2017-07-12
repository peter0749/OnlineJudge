//#pragma GCC target ("avx")
#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <assert.h>

using std::vector;
vector<double> y_search;
struct SegmentTree {
    enum{ MAXN=410, TREEND=4, TREENN=MAXN*TREEND};
    int  seg[TREENN]; // neg, pos
    int  lazy[TREENN]; // neg, pos
    double  range[TREENN]; // neg, pos

#define HALF_OPEN_INTERVAL
    inline int LEFT(const int &i) { return i<<1; }
    inline int RIGHT(const int &i) { return i<<1|1; }
    inline void init(int n) {
        n*=TREEND;
        std::fill(this->seg, this->seg+n+1, 0);
        std::fill(this->range, this->range+n+1, 0.0);
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
    inline void _pull(int lev, int L, int R) {
        range[lev] = seg[lev]>0?(y_search[R]-y_search[L]):(range[LEFT(lev)]+range[RIGHT(lev)]);
    }
    void update(int L, int R, int qL, int qR, int lev, int op) {
        assert(lev<TREENN);
        if (OO_RANGE) return;
        int M = (L+R)>>1;
        if (IN_RANGE) {
            seg[lev] += (op?1:-1);
            lazy[lev] += (op?1:-1);
            range[lev] = seg[lev]>0?(y_search[R]-y_search[L]):(range[LEFT(lev)]+range[RIGHT(lev)]);
            return;
        }
        update(L, M, qL, qR, LEFT(lev), op);
#ifndef HALF_OPEN_INTERVAL
        update(M+1, R, qL,qR, RIGHT(lev),op);
#else
        update(M, R, qL,qR, RIGHT(lev),op);
#endif
        _pull(lev, L, R);
    }

    inline double query(int R) {
        return range[1];
    }
#undef IN_RANGE
#undef OO_RANGE
#undef LEFT
#undef RIGHT
#undef HALF_OPEN_INTERVAL
};

struct NODE {
    NODE(double x, double y1, double y2, bool state): x(x), y1(y1), y2(y2), state(state) {}
    double x, y1, y2;
    bool state; // 1, enter; 0, exit
};
const bool operator<(const NODE &left, const NODE &right) {
    if (left.x!=right.x) return left.x<right.x;
    return left.state > right.state; // reverse order
}

using namespace std;
SegmentTree *tree;
vector<NODE> data;
set<double> yseg;

int main(void) {
    int N;
    int T=0;
    tree = new SegmentTree;
    while(scanf("%d",&N)==1 && N) {
        data.clear();
        yseg.clear();
        y_search.clear();
        for (int i=0; i<N; ++i) {
            double x1, y1, x2, y2;
            scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
            if (y1>y2) swap(y1,y2);
            data.push_back(NODE(x1,y1,y2,true));
            data.push_back(NODE(x2,y1,y2,false));
            yseg.insert(y1); yseg.insert(y2);
        }
        sort(data.begin(),data.end());
        y_search.reserve(yseg.size()+1);
        y_search.push_back(-2); // not used
        for (set<double>::iterator v=yseg.begin(); v!=yseg.end(); ++v)
            y_search.push_back(*v);
        int segN = yseg.size();
        yseg.clear();
        tree->init(segN);
#define FIND_IDX(_X) (lower_bound(y_search.begin(), y_search.end(), ( _X) )-y_search.begin())
        tree->update(1, segN, FIND_IDX(data[0].y1), FIND_IDX(data[0].y2), 1, 1);
        NODE left = data[0];
        double sum=0.0;
        for (vector<NODE>::iterator v=data.begin()+1; v!=data.end(); ++v) {
            NODE &inst = *v;
            int idxy1 = FIND_IDX(inst.y1);
            int idxy2 = FIND_IDX(inst.y2);
            sum += tree->query(segN) * (inst.x-left.x);
            tree->update(1, segN, idxy1, idxy2, 1, inst.state);
            left = inst;
        }
        ++T;
        printf("Test case #%d\n",T);
        printf("Total explored area: %.2f\n\n", sum);
    }
    delete tree;
    return 0;
}