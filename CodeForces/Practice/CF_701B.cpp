#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

vector<bool> rows(MAX), cols(MAX);
long long int nrows, ncols;

int main(void)
{
    ios::sync_with_stdio(false);
    long long int n, m, r, c;
    while(cin>>n>>m)
    {
        nrows = ncols = n;
        fill(rows.begin(),rows.end(),true);
        fill(cols.begin(),cols.end(),true);
        for(long long int i=0; i<m ;i++)
        {
            cin>>r>>c;
            if(rows.at(r))
            {
                rows.at(r) = false;
                nrows--;
            }
            if(cols.at(c))
            {
                cols.at(c) = false;
                ncols--;
            }
            if(i!=0) cout<<' ';
            cout<<nrows*ncols;
        }
        cout<<'\n';
    }
    return 0;
}
