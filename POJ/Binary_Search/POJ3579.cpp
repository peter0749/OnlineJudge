#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <ctime>
#include <stdexcept>
using namespace std;

class solver {
    private:
        inline int absll(int a) { return a<0?-a:a; }
        vector<int> data;
        int tar;
        inline bool io(void) {
            int n;
            if(scanf("%d",&n)==EOF) return false;
            data.clear();
            for(int i=0; i!=n; ++i) {
                int t;
                scanf("%d",&t);
                data.push_back(t);
            }
            return true;
        }
        inline void shu(vector<int> &in) {
            for(vector<int>::iterator v=in.begin(); v!=in.end(); ++v) {
                swap( *v, in.at(rand()%in.size()) );
            }
        }

        inline bool check( int m) {
            int counter=0;
            deque< int>que;
            int i=0;
            while (i-que.size()<data.size()) {
                for(; i<data.size() && (que.empty()||data.at(i)-que.front() <=m) ; ++i) que.push_back(data.at(i));
                if(!que.empty()) que.pop_front();
                counter += que.size();
                if(counter>=this->tar) return true;
            }
            return false;
        }
        int sol() {
            sort(data.begin(), data.end());
            int ub=*max_element(data.begin(), data.end()) - *min_element(data.begin(), data.end());
            int lb=-1;
            this->tar = ( ( data.size() * (data.size()-1) )/2 + 1 ) / 2;
            while(ub-lb>1) {
                int mid=((lb+ub)>>1);
                if(check(mid)) {
                    ub=mid;
                }
                else lb=mid;
            }
            return ub;
        }
    public:
        inline void solveit() {
            while(io()) {
                printf("%d\n",sol());
            }
        }
        solver() {
            srand(11);
        }
};

int main(void) {
    solver sol;
    sol.solveit();
    return 0;
}
