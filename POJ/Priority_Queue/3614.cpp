#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
typedef pair<int, int> PII;
vector< PII > queC, queL;
bool mark[100000];
int C, L;

int main(void){
    int u, v;
    PII LLL, CCC;
    int counter;
    while(scanf("%d%d", &C, &L)==2){
        counter = 0;
        for(int i=0; i<C; ++i){
            scanf("%d%d", &u, &v);
            queC.push_back(make_pair(v,u));
        }
        for(int i=0; i<L; ++i){
            scanf("%d%d", &u, &v);
            queL.push_back(make_pair(u,v));
        }
        sort(queC.begin(), queC.end(), less< PII >() );
        sort(queL.begin(), queL.end(), less< PII >() );
        memset(mark,0x00,sizeof(mark));
        for(int i=0; i<queL.size(); ++i){
            for(int j=0; j<queC.size(); ++j){
                if( queL[i].second && !mark[j]&&\
                    queC[j].second <= queL[i].first &&\
                    queL[i].first <=  queC[j].first\
                    ){
                    queL[i].second--;
                    counter++;
                    mark[j]=true;
                }
            }
        }
        printf("%d\n", counter);
        queC.clear();
        queL.clear();
    }
    return 0;
}
