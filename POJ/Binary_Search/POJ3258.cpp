#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
class Solver {
    private:
        vector<int> stone;
        int L, N, M;
    public:
        bool io_sec(void) {
            if(scanf("%d%d%d",&L,&N,&M)!=3) return false;
            stone.clear();
            stone.push_back(0);
            for(int i=0; i!=N; ++i) {
                int t; scanf("%d",&t);
                stone.push_back(t);
            }
            stone.push_back(L);
            sort(stone.begin(), stone.end());
            //for(int v: stone) cout<<v<<endl;
            N+=2;
            M=N-M;
            return true;
        }

        bool check(int d) {
            int last=0;
            for (int i=1; i<M; ++i) {
                int crt = last+1;
                while (crt < N && stone[crt] - stone[last] < d) ++crt;
                if(crt==N) return false;
                last = crt;
            }
            return true;
        }

        int sol(void) {
            sort(stone.begin(), stone.end());
            int lb=0, ub=1e9+7;
            while (ub - lb > 1) {
                int mid = ((unsigned int )lb+(unsigned int )ub)>>1;
                if( check(mid) ) lb=mid;
                else ub=mid;
            }
            return lb;
        }

        inline void mainLoop() {
            io_sec();
            printf("%d\n",sol());
        }

};

int main(void) {
    Solver sol;
    sol.mainLoop();
    return 0;
}
