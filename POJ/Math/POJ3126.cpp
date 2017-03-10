#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstdlib>
#include <cstring>
#include <climits>
using namespace std;

typedef long long int UT;
const size_t MAXN=9999;
vector<int>plist;
bool is_prime[MAXN];

void mk_prime() {
    fill(is_prime, is_prime+MAXN, true);
    is_prime[1]=is_prime[0]=false;
    plist.push_back(2);
    for(int i=3; i<MAXN; i+=2) {
        if(is_prime[i]) {
            plist.push_back(i);
            for(int j=i+i; j<MAXN; j+=i) is_prime[j]=false;
        }
    }
}

inline bool is_p(int n) {
    if(n==2) return true;
    if(n%2==0) return false;
    if(n<MAXN) return is_prime[n];
    for(vector<int>::iterator v=plist.begin(); v!=plist.end() && (*v)*(*v)<=n; ++v) {
        if(n%(*v)==0) return false;
    }
    return true;
}

int minv, tar;
int se[]={1,10,100,1000,10000};
bool vis[10010];
int bfs(int n, int tar) {
    queue< pair<int,int> > que;
    memset(vis,0x00,sizeof(vis));
    que.push(make_pair(0,n));
    while(1) {
        while(!que.empty() && vis[que.front().second])que.pop(); // DFS here!?!? The statement should be always false
        if(que.empty())break;
        pair<int,int> ele=que.front(); que.pop();
        vis[ele.second]=true;
        if(ele.second==tar) return ele.first;
        //cout<<ele.first<<' '<<ele.second<<endl;
        for(int i=0; i<4; ++i) {
            int t=((ele.second/se[i+1])*se[i+1])+(i?(ele.second%se[i]):0);
            for(int j=(i==3?1:0); j<=9; ++j) {
                int t1=t+se[i]*j;
                if(t1==tar) return ele.first+1;
                if(t1!=ele.second && !vis[t1] && is_p(t1)) {
                    que.push(make_pair(ele.first+1, t1));
                }
            }
        }
    }
    return -1;
}

int main(void) {
    UT a,p;
    mk_prime();
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
        int a, b;
        scanf("%d%d",&a,&b);
        int res=bfs(a,b);
        if(res==-1) puts("Impossible");
        else printf("%d\n",res);
    }
    return 0;
}
