#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class EDGE { 
    public:
        int from, to, cost;
        bool operator<( const EDGE &foo) const {
            return this->cost < foo.cost;
        }
        bool operator>( const EDGE &foo) const {
            return this->cost > foo.cost;
        }
        EDGE(int a, int b, int c) { 
            this->from=a, this->to=b, this->cost=c;
        }
};

class Solution {
#define _PB push_back
    private:
        vector< EDGE > edge;
        int V;
        int *par, *rank;
        void init_uni() {
            int i((edge.size()+1)<<1);
            par = new int[i];
            rank = new int[i];
            while(i--) {
                par[i]=i;
                rank[i]=1;
            }
        }
        void des_uni() {
            delete[] par;
            delete[] rank;
            par = rank = NULL;
        }
        int find(int foo) { 
            return foo==par[foo]?foo:(par[foo]=find(par[foo]));
        }
        bool same(int foo, int bar) {
            return find(foo)==find(bar);
        }
        void uni(int x, int y) {
            x = find(x);
            y = find(y);
            if(x==y) return;
            if(rank[x]<rank[y]) par[x]=y;
            else {
                par[y]=x;
                if(rank[x]==rank[y]) ++rank[x];
            }
        }
        void read() {
            int E;
            scanf("%d%d",&V,&E);
            for(int i=0; i!=E; ++i) {
                int f,t,c;
                scanf("%d%d%d",&f,&t,&c);
                edge._PB(EDGE(f,t,c));
            }
        }

        int kk() {
            //pass
            sort(edge.begin(), edge.end(), greater< EDGE >() );
            init_uni();
            int res=0;
            for(int i=0; i!=edge.size(); ++i) {
                EDGE e = edge[i];
                if(!same(e.from, e.to)) {
                    uni(e.from, e.to);
                    res+=e.cost;
                }
            }
            int c=1, counter=0; //Tree counter
            for(; c<=V && counter<=1; ++c) if(c==find(c)) ++counter;
            des_uni();
            return counter==1?res:-1;
        }
    public:
        int solv() {
            read();
            return kk();
        }
        Solution() {
            par = rank = NULL;
        }
};

int main(void) {
    Solution solv;
    printf("%d\n",solv.solv());
    return 0;
}
