#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long int val;    // 用於修改、更新的值
    int lc, rc; // 左右子樹的 index
};

struct SegmentTreeP {
    enum {QUERY_NUM=510101, TREENN=8200000};
    int root[QUERY_NUM]; // 為了方便，寫死就好，這用來記錄線段樹的更新 root
    int node_num;
    Node node[TREENN];

    SegmentTreeP() : node_num(0) {}
    
    int build(int l, int r) { // 傳回更新節點指標（不是指記憶體指標）
        if (l>r) return 0; // illegal
        int new_node = node_num++;
        node[new_node].lc = node[new_node].rc = node[new_node].val = 0;
        if (l==r) return new_node;
        int m = l+((r-l)>>1); 
        node[new_node].lc = build(l, m);
        node[new_node].rc = build(m+1, r);
        return new_node;
    }
    void init_build(int l, int r) {
        root[0] = build(l, r);
    }
    int update(int acs, int l, int r, int q, int val) {
        int new_node = node_num++;
        node[new_node] = node[acs];
        if (l==r) {
            node[new_node].val = val;
            return new_node;
        }
        int m = l+((r-l)>>1);
        if (q <= m)
            node[new_node].lc = update(node[acs].lc, l, m, q, val);
        else 
            node[new_node].rc = update(node[acs].rc,m+1,r, q, val);
        node[new_node].val = node[node[new_node].lc].val + \
                             node[node[new_node].rc].val;
        return new_node;
    }
    long long int query(int acs, int l, int r, int ql, int qr) {
        if (r<ql || l>qr) return 0LL;
        if (l>=ql && r<=qr) return node[acs].val;
        int m = l+((r-l)>>1);
        long long int sum = 0;
        if (ql <= m)
            sum += query(node[acs].lc,  l, m, ql, qr);
        if (m  < qr)
            sum += query(node[acs].rc,m+1, r, ql, qr);
        return sum;
    }
};

SegmentTreeP *st;

int main(void) {
    int N, M;
    st = NULL;
    st = new SegmentTreeP;
    assert(st!=NULL);
    SegmentTreeP &Solver = *st;
    while (scanf("%d%d",&N,&M)==2) {
        Solver.init_build(1, N);
        int preVer=0, op, l, r;
        for (int i=1; i<=M; ++i) {
            scanf("%d%d",&op, &l);
            switch (op) {
                case 0: {
                    int rec = max(0,i-1-l);
                    Solver.root[i] = Solver.root[rec];
                    preVer = i;
                        }
                    break;
                case 1: {
                    scanf("%d", &r);
                    Solver.root[i] = Solver.update(Solver.root[preVer], 1, N, l, r);
                    preVer = i;
                        }
                    break;
                case 2: {
                    scanf("%d", &r);
                    printf("%lld\n", Solver.query(Solver.root[preVer], 1, N, l, r));
                    Solver.root[i] = Solver.root[preVer];
                    preVer = i;
                        }
                    break;
            }
        }
    }
    return 0;
}
