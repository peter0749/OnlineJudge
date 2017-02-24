#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define W first
#define T second
using namespace std;

class Solution {
    typedef pair<int,int> EDGE; // weight, to
    private:
        vector< EDGE > *V;
        vector< EDGE > *R;
        int *dist, *rdist;
        int N, M, X;
        int infi;
        void init() {
            V = new vector< EDGE >[N+1];
            R = new vector< EDGE >[N+1];
            dist = new int[N+1];
            rdist = new int[N+1];
        }
        inline void link(int u, int v, int w) {
            V[u].push_back(make_pair(w,v)); 
            R[v].push_back(make_pair(w,u)); 
        }
        void des() {
            delete[] R; delete[] V;
            delete[] dist; delete[] rdist;
        }
        void read_data() {
            scanf("%d%d%d", &N, &M, &X);
            --X;
            init();
            int u, v, w;
            for(int i=0; i!=M; ++i) {
                scanf("%d%d%d",&u,&v,&w);
                link(u-1,v-1,w);//0-base
            }
        }
        void dij( vector< EDGE >*& E, int *&d, int src ) {
            priority_queue< EDGE, vector< EDGE >, greater< EDGE > > que;
            fill(d,d+N,infi);
            d[src]=0;
            que.push(make_pair(0,src));
            while(!que.empty()) {
                EDGE pii=que.top(); que.pop();
                if(pii.W>d[pii.T]) continue;
                for( vector< EDGE >::iterator v=E[pii.T].begin(); v!=E[pii.T].end(); ++v) {
                    if(d[v->T]>pii.W+v->W) {
                        d[v->T]=pii.W+v->W;
                        que.push(make_pair(d[v->T], v->T));
                    }
                }
            }
        }
        void print_dist() {
            for(int i=0; i!=N; ++i) printf("%d ", dist[i]);
            puts("");
            for(int i=0; i!=N; ++i) printf("%d ", rdist[i]);
            puts("");
        }
        int find_max() {
            int res=-1e9;
            for(int i=0; i!=N; ++i) res=max(res,dist[i]+rdist[i]);
            return res;
        }
    public:
        int solv() {
            read_data();
            dij(V, dist, X);
            dij(R, rdist, X);
            int res=find_max();
            //print_dist();
            des();
            return res;
        }
        Solution(){
            infi=1e9+7;
        }
};

int main(void) {
    Solution sol;
    printf("%d\n",sol.solv());
    return 0;
}
