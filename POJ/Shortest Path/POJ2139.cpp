#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const size_t MAXN=305, MAXM=10005;
const int INF=1e9;
int deg[MAXN][MAXN];

inline void init(void) {
    for(size_t i=0; i!=MAXN; ++i) for(size_t j=0; j!=MAXN; ++j) deg[i][j]=INF;
    for(size_t i=0; i!=MAXN; ++i) deg[i][i]=0;
}

inline void link(int *arr, int N) {
    for(int i=0; i<N-1; ++i) {
        for(int j=i+1; j<N; ++j) {
            deg[ arr[i] ][ arr[j] ]=1;
            deg[ arr[j] ][ arr[i] ]=1;
        }
    }
}

void FW(int N) {
    for(int k=0; k!=N; ++k) {
        for(int i=0; i!=N; ++i) {
            for(int j=0; j!=N; ++j) {
                deg[i][j]=min(deg[i][j],deg[i][k]+deg[k][j]);
            }
        }
    }
}

int MM_mean(int N) {
    int minval=1e9+7;
    for(int i=0; i!=N; ++i) {
        int acc=0;
        for(int j=0; j!=N; ++j) acc+=(deg[i][j]);
        //it is guaranteed that some relationship path exists between every pair of cows. 
        minval=min(minval, acc);
    }
    return (int)( (double)minval/(double)(N-1)*(double)100.0  );
}

int arr[MAXN];
int main(void) {
    int N, M, n;
    init();
    scanf("%d%d",&N,&M);
    for(int i=0; i!=M; ++i) {
        scanf("%d",&n);
        for(int j=0; j!=n; ++j) { scanf("%d",arr+j); --arr[j];}//to 0-base
        link(arr, n);
    }
    FW(N);
    printf("%d\n", MM_mean(N));
    /*
    for(int i=0; i!=N; ++i) {
        for(int j=0; j!=N; ++j) {
            printf("%d ", deg[i][j]);
        }
        puts("");
    }
    */
    return 0;
}
