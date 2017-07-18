#pragma GCC target ("avx")
#pragma GCC optimize ("Os")
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int lc, rc;
    long long val;
};

struct SegmentTreeP {
    enum { MAXNODE=6101010, MAXREC=500010};
    int nodeNum;
    int his[MAXREC];
    Node sg[MAXNODE];
    SegmentTreeP() : nodeNum(0) { }
    int build(int l, int r) {
        if (l>r) return 0; // illegal
        int k = nodeNum++; // allocate new node
        sg[k].lc = sg[k].rc = sg[k].val = 0;
        if (l==r) return k;
        int m = l+((r-l)>>1);
        sg[k].lc = build(l, m);
        sg[k].rc = build(m+1, r);
        return k;
    }
    void init(int N) {
        memset(his,0x00,sizeof(his[0])*MAXREC);
        memset(sg, 0x00,sizeof(sg[0])*MAXNODE);
        nodeNum = 0;
        his[0] = build(1,N);
    }
    int update(int acs, int l, int r, int q, long long val) {
        if (l>r) return 0;
        int k = nodeNum++;
        sg[k] = sg[acs];   // new node derived from acs
        if (l==r) { // modify
            sg[k].val = val;
            return k;
        }
        int m = l+((r-l)>>1);
        if (q<=m) 
            sg[k].lc = update(sg[acs].lc, l, m, q, val);// update left
        else 
            sg[k].rc = update(sg[acs].rc, m+1, r, q, val);// update right
        sg[k].val= sg[sg[k].lc].val + sg[sg[k].rc].val; // update
        return k;
    }
    long long query(int l, int r, int ql, int qr, int q) {
        if (l>r || l>qr || r < ql) return 0LL; // illegal
        if (l>=ql && r<=qr) { // in range
            return sg[q].val;
        }
        int m = l+((r-l)>>1);
        long long res = 0;
        if (ql<=m)
            res += query(l, m, ql, qr, sg[q].lc);
        if (m< qr)
            res += query(m+1, r, ql, qr, sg[q].rc);
        return res;
    }
};

int main(void) {
    SegmentTreeP *newTree = NULL;
    newTree = new SegmentTreeP();
    assert(newTree!=NULL);
    SegmentTreeP &tree = *newTree;
    int N, Q;
    while(scanf("%d%d", &N, &Q)==2) {
        tree.init(N);
        int preVer = 0;
        for (int i=1; i<=Q; ++i) {
            int op, l, r;
            scanf("%d%d", &op, &l);
            switch(op) {
                case 0: {
                            int rec = max(0, i-l-1);
                            tree.his[i] = tree.his[rec];
                            preVer = i;
                        }
                        break;
                case 1:
                        scanf("%d", &r);
                        tree.his[i] = tree.update(tree.his[preVer], 1,N,l,r);
                        preVer = i;
                        break;
                case 2:
                        scanf("%d", &r);
                        printf("%lld\n", tree.query(1,N,l,r,tree.his[preVer]));
                        tree.his[i] = tree.his[preVer];
                        preVer = i;
                        break;
            }
        }
    }
    delete newTree;
    return 0;
}
