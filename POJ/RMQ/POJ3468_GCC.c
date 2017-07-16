#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buff[50000000];
long long int seg[500100];
long long int lazy[500100];

void init() {
    memset(buff,0x00,sizeof(buff));
    memset(seg,0x00,sizeof(seg));
    memset(lazy,0x00,sizeof(lazy));
}

void push(int idx, int L, int M, int R) {
    if(lazy[idx]==0LL) return;
    // 壓懶標記
    lazy[idx<<1] += lazy[idx];
    lazy[idx<<1|1] += lazy[idx];
    seg[idx<<1] += lazy[idx]*(long long int)(M-L+1);
    seg[idx<<1|1] += lazy[idx]*(long long int)(R-M);
    lazy[idx] = 0LL; // reset lz tag
}

void pull(int idx, int L, int M, int R) {
    seg[idx] = seg[idx<<1|1]+seg[idx<<1];
}

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
    pull(idx, L, M, R);
}

long long query(int L, int R, int qL, int qR, int idx) {
    if (L>qR || R<qL) return 0LL;
    if (L>=qL && R<=qR) return seg[idx];
    int M = L+((R-L)>>1);
    push(idx, L, M, R);
    long long l=0, r=0;
    l = query(L,M,qL,qR,idx<<1);
    r = query(M+1,R,qL,qR,idx<<1|1);
    pull(idx, L, M, R);
    return l+r;
}

#define RL() fgets(buff, sizeof(buff)-100, stdin)
int main(void) {
    int N, Q, i;
    char *readPtr=NULL;
    RL();
    sscanf(buff, "%d%d", &N, &Q);
    RL();
    i=1;
    readPtr = strtok(buff, " \n");
    while(readPtr) {
        long long int input=0;
        sscanf(readPtr, "%lld", &input);
        update(1, N, i, i, 1, input);
        readPtr = strtok(NULL, " \n");
        ++i;
    }
    while(Q--) {
        char op;
        int l, r;
        long long int x;
        RL();
        int cnt = sscanf(buff, "%1c %d %d %lld", &op, &l, &r, &x);
        if (cnt==4) { //update
            update(1, N, l, r, 1, x);
        } else {
            printf("%lld\n", query(1,N,l,r,1));
        }
    }

    return 0;
}
