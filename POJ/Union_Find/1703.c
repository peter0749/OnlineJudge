#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RL fgets(temp,sizeof(temp),stdin)
#define MAXN 200005
int T, N, M;
int par[MAXN], rank[MAXN];

void init(){
    int i=((N+1)<<1);
    while(i--){
        par[i]=i;
        rank[i]=1;
    }
}

int find(int foo){ return foo==par[foo]?foo:(par[foo]=find(par[foo])); }
char same(int foo, int bar) { return find(foo)==find(bar); }
void uni(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(rank[x]<rank[y]) par[x]=y;
    else {
        par[y]=x;
        if(rank[x]==rank[y]) ++rank[x];
    }
}

int main(void) {
    int u, v;
    int i;
    char temp[200], op;
    RL; T=atoi(temp);
    while(T--){
        RL;
        sscanf(temp,"%d %d", &N, &M);
        init();
        for(i=0; i<M; ++i){
            RL;
            sscanf(temp, "%c %d %d", &op, &u, &v);
            switch(op){
                case 'D':
                    uni(u, v+N); uni(u+N, v);
                break;
                default:
                    if( same(u,v) || same(u+N, v+N) ){
                        puts("In the same gang.");
                    } else if( same(u,v+N)||same(u+N,v) ) {
                        puts("In different gangs.");
                    } else puts("Not sure yet.");
                break;
            }
        }
    }
    return 0;
}
