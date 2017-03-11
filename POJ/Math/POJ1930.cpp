#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
int se[]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

inline int str2b(string &s) {
    int res=0;
    for(string::iterator v=s.begin(); v!=s.end(); ++v) {
        res*=10;
        res+=(*v-'0');
    }
    return res;
}

pair<int,int> solv(string s, int m) {
    int a=str2b(s);
    a-=(a/se[m+1]);
    int n=s.length()-m;
    int b=0;
    for(int i=0; i!=m; ++i) {b*=10; b+=9;}
    b*=se[n+1];
    int g=__gcd(a,b);
    return make_pair(a/g,b/g);
}

int main(void) {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    string str;
    int p, q, r;
    while(cin>>str&&str!="0") {
        int minval=-1;
        pair<int,int>ans(INT_MAX,INT_MAX);
        for(int i=str.length()-5; i>=1; --i) {
            int off=str.find('.',2);
            pair<int,int>temp=solv(str.substr(2,off-2),i);
            if(temp.second<ans.second) ans=temp;
        }
        cout<<ans.first<<"/"<<ans.second<<'\n';
    }
    return 0;
}
