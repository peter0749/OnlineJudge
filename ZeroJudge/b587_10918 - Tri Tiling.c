#include <stdio.h>
#include <stdlib.h>
#define MAX 31

int DP[MAX];

int rec(int n)
{
    int i;
    if(n&1) return 0;//Odd
    else if(DP[n]!=0)   return DP[n];
    else if(n==0)    return (DP[n]=1);
    else if(n==2)   return (DP[n]=3);
    else if(n==4)   return (DP[n]=11);
    else if(n>=6)
    {
        for(i = 4; i<=n; i+=2)
            DP[n]+=rec(n-i);
        DP[n]<<=1;
        DP[n]+=3*rec(n-2);
        return DP[n];
    }
    return 0;
}

int main(void)
{
    int i;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)break;
        for(i=0;i<=n;i++)
            DP[i]=0;
        printf("%d\n",rec(n));
        //for(i=0;i<=n;i++)printf("DP[%d] = %d\n",i,DP[i]);
    }
    return 0;
}
