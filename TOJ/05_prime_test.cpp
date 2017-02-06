#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>

#define MAX 50000

using namespace std;

bool book[MAX] = {false};
int prime_list[5200] = {0};

void mk_prime(void)
{
    int i, j, counter=0;
    for(i=3; i<MAX; i+=2)
    {
        if(book[i]==false)
        {
            for(j=(i<<1); j<MAX; j+=i)
            {
                book[j]=true;
            }
            prime_list[counter] = i;
            //cout<<prime_list[counter]<<endl;
            counter++;
        }
    }
    //cout<<prime_list[counter-1]<<endl;
    //cout<<counter<<endl;
}

bool is_prime(int n)
{
    if(n==1)    return false;
    if(n==2)    return true;
    if(n%2==0)  return false;
    if(n<MAX)   return !book[n];
    for(int i=0; prime_list[i]*prime_list[i]<=n && prime_list[i]!=0; i++)
    {
        if(n%prime_list[i]==0)  return false;
    }
    return true;
}

int main(void)
{
    int term, n, op;
    mk_prime();
    scanf("%d",&term);
    //cin>>term;
    while(term--)
    {
        //cin>>n;
        scanf("%d",&n);
        op = is_prime(n);
        if(op)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
