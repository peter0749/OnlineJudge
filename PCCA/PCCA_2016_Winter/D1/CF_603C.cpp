#include <bits/stdc++.h>
using namespace std;
int t, n, k, t1, t2;

int compute( int x ) {
    int sub = 0;
    if(x==0) return 0;
    if(!(x&1)) {//even
        sub = (k&1)?compute(x>>1):0;
        t1 = compute(x-1);
        t2 = min(t1, sub);
        if(t2>0) return 0;
        if(abs(sub-t1)>1) return t2+1;
        return max(t1, sub)+1;
    }
    return (x>4) ? 0: ((sub=compute(x-1))?0:sub+1);
}

int main(void) {
    int temp=0;
    while((scanf("%d%d",&n,&k))==2) {
        temp = 0;
        for(int i=0;i<n;++i) {
            scanf("%d",&t);
            t = compute(t);
            temp ^= t;
        }
        printf(temp?"Kevin\n":"Nicky\n");
    }
    return 0;
}
