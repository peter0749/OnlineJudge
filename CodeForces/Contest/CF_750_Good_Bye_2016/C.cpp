#include <bits/stdc++.h>
#define PB push_back
#define X first
#define Y second
#define MAXN 10000
using namespace std;
typedef pair< int, int > PII;
typedef vector< int > VEC;

int main(void) {
    int N, sum=0, r, d;
    int lb=-1e9, rb=1e9;
    scanf("%d", &N);
    for(int i=0; i<N && lb<=rb; ++i) {
        scanf("%d%d",&r, &d);
        switch(d) {
            case 1:
                lb = max(lb,1900-sum);
            break;
            case 2:
                rb = min(rb,1899-sum);
            break;
        }
        sum+=r;
    }
    if(lb>rb) printf("Impossible\n");
    else if(rb==1e9) printf("Infinity\n");
    else printf("%d\n",rb+sum);
    return 0;
}
