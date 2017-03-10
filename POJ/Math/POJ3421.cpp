#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

map<int,int> pd(int n) {
    map<int,int> r;
    for(int i=2; i*i<=n; ++i) {
        while(n%i==0) {
            ++r[i];
            n/=i;
        }
    }
    if(n!=1) r[n]=1;
    return r;
}

long long int P[30];
void p(int n) {
    long long int ans=1;
    for(int i=1; i<=n; ++i) {
        ans*=i;
        P[i]=ans;
    }
}

pair<int,long long int> solv(int n) {
    map<int,int> d=pd(n);
    long long int cnt=0;
    int len=0;
    for(map<int,int>::iterator v=d.begin(); v!=d.end(); ++v) {
        len+=(v->second);
    }
    cnt=P[len];
    for(map<int,int>::iterator v=d.begin(); v!=d.end(); ++v) {
        cnt /= P[(v->second)];
    }
    return make_pair(len, cnt);
}


int main(void) {
    int n;
    p(20);
    while(scanf("%d",&n)!=EOF) {
        pair<int,long long int> ans=solv(n);
        printf("%d %lld\n",ans.first, ans.second);
    }
    return 0;
}
