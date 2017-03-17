#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

class Solution{
    private:
        vector<int>data;
        int N, M;
        inline void readIO(void) {
            scanf("%d%d",&N,&M);
            for(int i=0; i<N; ++i) {
                int t; scanf("%d",&t);
                data.push_back(t);
            }
        }
        bool check(int d) {
            int counter=1;
            int sum=0;
            for(int i=0; i<N; ++i) {
                if(data.at(i)>d) return false;
                int t=sum+data.at(i);
                if(t <= d ) sum+=data.at(i);
                else { // t > d
                    sum=data.at(i);
                    ++counter; // start new set
                }
                if(counter>M) return false;
            }
            return true;
        }
        int sol(void) {
            int lb=0, ub=1e9+7;
            while(ub-lb>1) {
                int mid=((unsigned int)lb+(unsigned int)ub)>>1;
                if(check(mid)) ub=mid;
                else lb=mid;
            }
            return ub;
        }
    public:
        void mainLoop(void) {
            data.clear();
            readIO();
            printf("%d\n", sol());
        }
};

int main(void) {
    Solution sol;
    sol.mainLoop();
    return 0;
}
