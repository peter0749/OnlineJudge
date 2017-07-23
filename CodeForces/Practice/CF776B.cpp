#include <bits/stdc++.h>
using namespace std;

const size_t MAXN=100010;
int col[MAXN];

int main(void) {
    int coln=0, n=0;
    scanf("%d",&n);
    memset(col,0x00,sizeof(col));
    for (int i=2; i<=n+1; ++i) {
        if (col[i]==0) {
            for (int j=i+i; j<=n+1; j+=i) {
                if (col[i]==col[j]) col[j]=col[i]+1;
            }
        }
    }
    coln = 0;
    for (int i=2; i<=n+1; ++i) coln=max(coln,col[i]);
    printf("%d\n1", coln+1);
    for (int i=3; i<=n+1; ++i) {
        printf(" %d", col[i]+1);
    }
    printf("\n");
    return 0;
}
