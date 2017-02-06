#include <bits/stdc++.h>
#define MAXLEN 200001
using namespace std;

vector<int> direction(MAXLEN);
vector<int> col(MAXLEN);
stack<int> teststk;

int main(void)
{
    ios::sync_with_stdio(false);
    int term, testcol;
    int mininval = 1100000001, temp;
    char testp;
    int t, u;
    while(cin>>term)
    {
        mininval = 1100000001;
        for(int i=0; i<term; i++)
        {
            cin>>testp;
            if(testp=='R')
            {
                direction.at(i) = 1;
            }
            else
            {
                direction.at(i) = -1;
                if(i>0 && direction.at(i-1)==1)
                {
                    teststk.push(i);
                }
            }
        }
        for(int i=0; i<term; i++)
        {
            cin>>col.at(i);
        }
        if(teststk.empty())
        {
            cout<<-1<<'\n';
        }
        else
        {
            while(!teststk.empty())
            {
                u = teststk.top();
                teststk.pop();
                temp = col.at(u) - col.at(u-1);
                if(temp<mininval)
                    mininval = temp;
            }
            cout<<mininval/2<<'\n';
        }
    }
}
