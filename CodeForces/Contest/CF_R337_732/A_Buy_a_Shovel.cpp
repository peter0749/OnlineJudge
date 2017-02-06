#include <bits/stdc++.h>
using namespace std;
typedef long long int LLD;

int main(void)
{
    ios::sync_with_stdio(false);
    int r, k, n;
    while(cin>>k>>r)
    {
        k%=10;
        n = 1;
        while( ((n%10)*k%10)!=0 && ((n%10)*k%10)!=r )n++;
        cout<<n<<'\n';
    }
    return 0;
}
