#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int seg[1500100];
long long int lazy[1500100];

#define push(idx, L, M, R) \
    if(lazy[idx]!=0LL) { \
        lazy[idx<<1] += lazy[idx]; \
        lazy[idx<<1|1] += lazy[idx]; \
        seg[idx<<1] += lazy[idx]*(long long int)(M-L+1); \
        seg[idx<<1|1] += lazy[idx]*(long long int)(R-M); \
        lazy[idx] = 0LL; } 


#define pull(idx) \
{ seg[idx] = seg[idx<<1|1]+seg[idx<<1]; }

void update(int L, int R, int qL, int qR, int idx, long long int val) {
    if (L>qR || R<qL) return;
    if (L>=qL && R<=qR) {
        seg[idx]+=(val*(R-L+1));
        lazy[idx]+=val;
        return; // 放懶標
    }
    int M = L+((R-L)>>1);

    push(idx, L, M, R);

    update(L, M, qL, qR, idx<<1, val);
    update(M+1, R, qL, qR, idx<<1|1, val);

    pull(idx);
}

long long query(int L, int R, int qL, int qR, int idx) {
    if (L>qR || R<qL) return 0LL;
    if (L>=qL && R<=qR) return seg[idx];
    int M = L+((R-L)>>1);

    push(idx, L, M, R);

    long long l=0, r=0;
    l = query(L,M,qL,qR,idx<<1);
    r = query(M+1,R,qL,qR,idx<<1|1);

    pull(idx);

    return l+r;
}
#undef push
#undef pull

int main(void) {
    int N, Q, i;
    scanf("%d", &N);
    for (i=1; i<=N; ++i) {
        long long int input;
        scanf("%lld", &input);
        update(1, N, i, i, 1, input);
    }
    scanf("%d", &Q);
    while(Q--) {
        int op;
        int l, r;
        long long int x;
        scanf("%d%d%d", &op, &l, &r);
        switch (op) {
            case 1:
                scanf("%lld", &x);
                update(1, N, l, r, 1, x);
                break;
            case 2:
                printf("%lld\n", query(1,N,l,r,1));
                break;
        }
    }
    return 0;
}
