#include <bits/stdc++.h>
#define MAXN 1000100
#define OPTIONAL_SEG_TREE
using namespace std;

int rec[MAXN],seg[MAXN<<2];

int n3(long long int n){
    /*
    //Real Code:
    int counter=1;
    if(n<MAXN && rec[n]) return rec[n];
    while(n!=1){
        n = n&1LL?3*n+1:n>>1;
        if(n<MAXN && rec[n]) return rec[n]+counter;
        counter++;
    }
    return counter;
    */
    return n==1?1:(n<MAXN&&rec[n]?rec[n]:n<MAXN?rec[n]=(n&1LL?n3(3*n+1):n3(n>>1))+1:(n&1LL?n3(3*n+1):n3(n>>1))+1);
}
#ifdef OPTIONAL_SEG_TREE
void build(int L, int R, int lev, int ori[], int seg[]){
    int M = (L+R)>>1;
    if(R==L){
        seg[lev] = ori[L];
        return;
    }
    build(L,M, lev<<1, ori, seg);
    build(M+1,R,lev<<1|1, ori, seg);
    seg[lev] = (L=seg[lev<<1])>(R=seg[lev<<1|1])?L:R;
}

int query(int L, int R, int qL, int qR, int flag, int seg[]){
    int t1, t2;
    int M=(L+R)>>1;
    if(L>qR || R<qL) return INT_MIN;
    if(qL<=L && qR>=R) return seg[flag];
    return (t1=query(L,M,qL,qR,flag<<1,seg))>(t2=query(M+1,R,qL,qR,flag<<1|1,seg))?t1:t2;
}
#endif
int main(void){
    int l, r, maxval;
    memset(rec,0,sizeof(rec));
    memset(seg,0,sizeof(seg));
    for(int i=1; i<MAXN; ++i) n3(i);
    #ifdef OPTIONAL_SEG_TREE
    build(1,MAXN-1,1,rec,seg);
    #endif
    while(scanf("%d%d",&l,&r)==2 && l!=0  && r!=0){
        printf("%d %d ",l,r);
        if(l>r)swap(l,r);
        #ifdef OPTIONAL_SEG_TREE
        printf("%d\n", query(1,MAXN-1,l,r,1,seg));
        #endif
        #ifndef OPTIONAL_SEG_TREE
        maxval = -1;
        for(int i=l; i<=r; ++i) maxval = max(maxval,rec[i]);
        printf("%d\n",maxval);
        #endif
    }
    return 0;
}
