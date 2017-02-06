#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1005

int par[MAXN];
int rank[MAXN];
int x[MAXN], y[MAXN];
char rep[MAXN];
int N, D;

void init(){
    int i;
    for(i=0; i<=N; ++i){
        par[i]=i;
        rank[i]=1;
    }
}

int find(int x){
    return x==par[x]? x: (par[x] = find(par[x]));
}

void uni(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(rank[x]<rank[y]){
        par[x] = y;
    }else {
        par[y] = x;
        if(rank[x]==rank[y]) ++rank[x];
    }
}

char same(int x, int y){
    return find(x)==find(y);
}

int main(void) {
    int a, b, i, ta, tb;
    char temp[MAXN], op;
    fgets(temp,MAXN,stdin);
    sscanf(temp, "%d %d",&N, &D);
    for(i=1; i<=N; ++i){
        fgets(temp, MAXN, stdin);
        sscanf(temp, "%d %d", &x[i], &y[i]);
    }
    memset(rep,0x00,N+1);//all ware broken
    init();
    while( (fgets(temp,MAXN,stdin))!=NULL){
        if (  sscanf(temp,"%c %d %d", &op, &a, &b)==3 ){//test a, b
            puts(same(a,b)?"SUCCESS":"FAIL");
        }else {//repair
            rep[a]=1;
            for(i=1; i<=N; ++i){
                if(rep[i]){
                    ta = x[a]-x[i]; ta*=ta;
                    tb = y[a]-y[i]; tb*=tb;
                    if(ta+tb<=D*D) uni(a,i);
                }
            }
        }
    }
    return 0;
}
