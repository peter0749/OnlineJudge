#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#define MAXN 3010

int par[MAXN], RANK[MAXN];

using namespace std;
pair<int, int> XY[MAXN];
bool repaired[MAXN];
int N;

void Initialize(){
    memset(repaired, 0x00 ,sizeof(repaired));
    int i=((N+1)<<1);
    while(i--){
        par[i]=i;
        RANK[i]=1;
    }
}

int Find(int foo){ return foo==par[foo]?foo:(par[foo]=Find(par[foo])); }
bool Same(int foo, int bar) { return Find(foo)==Find(bar); }
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x==y) return;
    if(RANK[x]<RANK[y]) par[x]=y;
    else {
        par[y]=x;
        if(RANK[x]==RANK[y]) ++RANK[x];
    }
}

#define RL() fgets(buff, 4000, stdin)

int main(void) {
    int d;
    char buff[4096];
    RL();
    sscanf(buff, "%d%d", &N, &d);
    Initialize();
    for (int i=1; i<=N; ++i) {
        int x , y;
        RL();
        sscanf(buff,"%d%d", &x, &y);
        XY[i] = make_pair(x,y);
    }
    while((RL())!=NULL) {
        char OP;
        int A, B;
        if (sscanf(buff, "%1c %d %d", &OP, &A, &B)==3) {
            printf( (Same(A,B)&&repaired[A]&&repaired[B])?"SUCCESS\n":"FAIL\n");
        } else {
            //Union(0,A); // repair
            repaired[A] = true;
            for (int i=1; i<=N; ++i) {
                int X = XY[i].first-XY[A].first;
                int Y = XY[i].second-XY[A].second;
                if ( repaired[i] && X*X+Y*Y <= d*d  ) {
                    Union(A,i);
                }
            }
        }
    }
    return 0;
}