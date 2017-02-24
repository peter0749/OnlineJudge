#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class Solution {
    typedef struct{int from, to, cost;}EDGE;
    private:
        int F, N, M, W;
        int ES;
        int *dist;
        EDGE *edge;
        void link(int from, int to, int cost, int lev) {
            --from; --to;
            edge[lev].from=from;
            edge[lev].to=to;
            edge[lev].cost=cost;
        }
        void init(void) {
            dist = new int[N+1];
            edge = new EDGE[M*2+W+1];
            ES=0;
        }
        void des(void) {
            delete[] dist; delete[] edge;
            ES=0;
        }
        void read_data() {
            scanf("%d%d%d", &N,&M,&W);
            init();
            int u, v, w;
            for(size_t i=0; i!=M; ++i) {
                scanf("%d%d%d", &u, &v, &w);
                link(u,v,w,ES);++ES;
                link(v,u,w,ES);++ES;
            }
            for(size_t i=0; i!=W; ++i) {
                scanf("%d%d%d", &u, &v, &w);
                link(u,v,-w,ES);++ES;
            }
        }
        bool find_negLoop(void) {
            memset(dist, 0, sizeof(dist));
            for(int i=0; i!=N; ++i) {
                for(int j=0; j!=ES; ++j) {
                    EDGE inst=edge[j];
                    if( dist[inst.to] > dist[inst.from]+inst.cost) {
                        dist[inst.to] = dist[inst.from]+inst.cost;
                        if(i==N-1) return true;
                    }
                }
            }
            return false;
        }
    public:
        void solv(void) {
            scanf("%d", &F);
            while(F--) {
                read_data();
                printf(( find_negLoop() )?"YES\n":"NO\n");
                //for(int i=0; i!=N; ++i) printf(" %d",dist[i]);
                //puts("");
                des();
            }
        }
};

int main(void) {
    Solution sol;
    sol.solv();
    return 0;
}
