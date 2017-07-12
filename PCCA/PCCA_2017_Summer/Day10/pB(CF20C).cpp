#pragma GCC target ("avx")
#pragma GCC optimize ("O3")
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
    typedef pair<unsigned long long int,int> EDGE; // weight, to
    private:
        vector< EDGE > *V;
        unsigned long long int *dist;
        int *pa;
        int N, M;
        int BD;
        void init() {
            BD = N + 300;
            V = new vector< EDGE >[BD];
            dist = new unsigned long long int[BD];
            pa = new int[BD];
        }
        inline void link(int u, int v, unsigned long long int w) {
            V[u].push_back(make_pair(w,v));
            V[v].push_back(make_pair(w,u));
        }
        void des() {
            delete[] V;
            delete[] dist; 
            delete[] pa;
        }
        void read_data() {
            scanf("%d%d", &N, &M); // node.num, edge.num
            init();
            int u, v, w;
            for(int i=0; i!=M; ++i) {
                scanf("%d%d%lld",&u,&v,&w);
                link(u,v,w);//0-base, undirected weighted graph
            }
        }
        void dij( vector< EDGE >*& E, unsigned long long int *&d, int src ) {
            priority_queue< EDGE, vector< EDGE >, greater< EDGE > > que;
            fill(d,d+BD,9223372036854775807uLL);
            fill(pa,pa+BD,0);
            d[src]=0;
            que.push(make_pair(0L,src));
            while(!que.empty()) {
                EDGE pii=que.top(); que.pop();
                if(pii.W>d[pii.T]) continue;
                for( vector< EDGE >::iterator v=E[pii.T].begin(); v!=E[pii.T].end(); ++v) {
                    if(d[v->T]>pii.W+v->W) {
                        d[v->T]=pii.W+v->W;
                        que.push(make_pair(d[v->T], v->T));
                        pa[v->T] = pii.T;
                    }
                }
            }
        }
        void bt(int from, int to) {
            vector<int> rev;
            if (pa[to]==0) {
                printf("-1\n");
                return;
            }
            for (int t=to, p=pa[to]; t!=0; p=pa[t=p])
                rev.push_back(t);
            bool first = true;
            for (vector<int>::reverse_iterator v=rev.rbegin(); v!=rev.rend(); ++v) {
                if(!first) printf(" ");
                printf("%d", *v);
                first = false;
            }
            printf("\n");
        }
    public:
        inline void solv() {
            read_data();
            dij(V, dist, 1);
            bt(1, N);
            des();
        }
        //Solution(){ }
};

int main(void) {
    Solution sol;
    sol.solv();
    return 0;   
}