#pragma GCC target ("avx")
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> s;

int main(void) {
    int t;
    while(scanf("%d",&t)!=EOF) {
        ++s[t];
    }
    unordered_map<int,int>::iterator i=s.begin();
    for (; i!=s.end()&&i->second!=2; ++i);
    printf("%d\n", i->first);
    return 0;
}