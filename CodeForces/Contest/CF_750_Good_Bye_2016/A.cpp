#include <bits/stdc++.h>
#define PB push_back
#define X first
#define Y second
#define MAXN 10000
using namespace std;
typedef pair< int, int > PII;
typedef vector< int > VEC;

int main(void) {
    ios::sync_with_stdio(false);
    int i, sum=0, n ,k;
    cin>>n>>k;
    i=0;
    do{
        ++i;
        sum+=(i*5);
    }while(sum<=240-k && i<=n);
    cout<<i-1<<'\n';
    return 0;
}
