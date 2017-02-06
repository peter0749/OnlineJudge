#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 5010

using namespace std;
typedef pair< int,int > PII;
vector< PII > input;
int trail[MAXN], top;

int main(void){
    int N, n,u ,v, i, j;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&n);
        input.clear();
        for(int i=0; i<n;++i){
            scanf("%d%d",&u,&v);
            input.push_back(make_pair(u,v));
        }
        sort(input.begin(), input.end(), less< PII >() );
        memset(trail,0x00,sizeof(trail));
        top = 0;
        trail[0] = input[0].second; ++top;
        for(i=1; i<input.size();++i){
           for(j=0; j<top && trail[j]>input[i].second; ++j);
           if(j!=top) trail[j]=input[i].second;
           else{
               trail[top++] = input[i].second;
           }
        }
        //for(i=0;i<top;++i) printf("## %d\n",trail[i]);
        printf("%d\n",top);
    }
    return 0;
}
