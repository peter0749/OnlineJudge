#include <bits/stdc++.h>
#define MAX 9
using namespace std;

char buffer[MAX];
char s[MAX];

inline void dfs(int crr, const int max_lev)
{
    if(crr==max_lev)
    {
        for(int i=0; i<max_lev; i++)
        cout<<(int)buffer[i];
        cout<<'\n';
        return;
    }
    for(int i=max_lev; i>=1; i--)
    {
        if(s[i])continue;
        buffer[crr]=i;
        s[i]=1;
        dfs(crr+1,max_lev);
        s[i]=0;
    }
}

int main(void)
{
    int n;
    ios::sync_with_stdio(false);
    for(int i=0; i<MAX; i++)s[i]=0;
    while(cin>>n)
    {
        dfs(0,n);
    }
    return 0;
}
