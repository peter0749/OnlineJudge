#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
const size_t MAXN=50000;
bool is_p[MAXN];
vector<int>plist;

void mk_p() {
    fill(is_p,is_p+MAXN,false);
    for(int i=5; i<MAXN; i+=4) is_p[i]=true;
    for(int i=5; i<MAXN; i+=4) {
        if(is_p[i]) {
            plist.push_back(i);
            for(int j=i+i; j<MAXN; j+=i) is_p[j]=false;
        }
    }
}

inline bool is_prime(int n) {
    if(n<MAXN) return is_p[n];
    for(vector<int>::iterator v=plist.begin(); v!=plist.end() && (*v)*(*v)<=n; ++v) {
        if(n%(*v)==0)return false;
    }
    return true;
}
inline bool is_hprime(int n) {
    if(n<MAXN && is_p[n]) return false;
    for(vector<int>::iterator v=plist.begin(); v!=plist.end() && (*v)*(*v)<=n; ++v) {
        if(n%(*v)==0 && is_prime(n/(*v)))return true;
    }
    return false;
}

vector<int>is_hp;

void build() {
    is_hp.clear();
    is_hp.push_back(0);
    for(int i=1; i<=1000002; i+=4) is_hp.push_back( is_hprime(i)?1:0 );
    for(vector<int>::iterator v=is_hp.begin()+1; v!=is_hp.end(); ++v) {
        *v = *v + *(v-1);
    }
}
int get_psum(int i, int j) {
    return is_hp.at(j) - is_hp.at(i-1);
}

int solv(int n) {
    return get_psum(1, ((n-1)/4)+1);
}  

int main(void) {
    int n;
    mk_p();
    build();
    while(scanf("%d",&n)!=EOF && n) {
        printf("%d %d\n",n , solv(n));
    }
    return 0;
}
