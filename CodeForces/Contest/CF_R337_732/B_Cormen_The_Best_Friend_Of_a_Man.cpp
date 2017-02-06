#include <bits/stdc++.h>
#define MAXN 600
using namespace std;
typedef long long int LLD;
int a[MAXN];

int main(void)
{
    ios::sync_with_stdio(false);
    int n, k, addi, t;
    while(cin>>n>>k)
    {
        addi = 0;
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=1; i<n; i++)
        {
            if( (t=a[i-1]+a[i]) < k)
            {
                a[i] += (t=k-t);
                addi += t;
            }
        }
        cout<<addi<<'\n'<<a[0];
        for(int i=1; i<n; i++) cout<<' '<<a[i];
        cout<<'\n';
    }
    return 0;
}
