#include <bits/stdc++.h>
#define MAX 150
#define DEBUG
using namespace std;

int dfsstk[MAX];
unsigned int testbit[MAX];
int sol_count=0;
int firstsol=1;

void prtout(const int n)
{
#ifdef DEBUG
    //char temp[MAX];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(dfsstk[i]==j)cout<<'Q';
            else cout<<'x';
        }
        cout<<'\n';
    }
    cout<<'\n';
#endif // DEBUG

}

int find_bit(const int n)
{
    int index = n/sizeof(int);
    int diff = n%sizeof(int);
    return testbit[index]&(1u<<diff);/*If found, return 1, else return 0.*/
}

void set_bit(const int n)
{
    int index = n/sizeof(int);
    int diff = n%sizeof(int);
    testbit[index] |= (1u<<diff);/*Set the nth bit.*/
}

void unset_bit(const int n)
{
    int index = n/sizeof(int);
    int diff = n%sizeof(int);
    testbit[index] &= ~(1u<<diff);/*unset the nth bit.*/
}

void dfs(int curr_d, const int max_d)
{
    int conflict(0);
    if(curr_d==max_d)
    {
        sol_count++;
        prtout(max_d);
    }
    else
    {
        for(int i=0; i<max_d; i++)
        {
            if(!find_bit(i))
            {
                for(int j=0; j<curr_d; j++)//o
                {
                    if(abs(dfsstk[j]-i)==(curr_d-j))
                    {
                        conflict=1;
                        break;
                    }
                }
                if(conflict)
                {
                    conflict=0;
                    continue;
                }
                //else
                dfsstk[curr_d] = i;
                set_bit(i);
                dfs(curr_d+1,max_d);
                unset_bit(i);
            }
        }
    }
}

int main(void)
{
    int first = 1;
    //freopen("testout.txt","w",stdout);
    cin.sync_with_stdio(false);
    int n;
    for(int i=0; i<MAX; i++)
    {
        testbit[i] = 0;
    }
    while(cin>>n)
    {
        if(n==0)break;
        firstsol=1;
        if(first)first=0;
        else cout<<'\n';
        sol_count=0;
        dfs(0,n);
        cout<<sol_count<<'\n';
    }
    return 0;
}
