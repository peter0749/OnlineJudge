#include <stdio.h>
#include <stdlib.h>
#define MAX 20

char data[MAX];

void dfs(int n, int stk_top, int lev)
{
    int i;
    if(lev==n)
    {
        if(stk_top!=-1) return;
        for(i=0; i<n; i++)
            putchar(data[i]);
        putchar('\n');
        return;
    }
    if(stk_top<-1)  return;
    if(stk_top> (n-lev))
    {
        data[lev]='\)';
        dfs(n, stk_top-1, lev+1);
    }
    else
    {
        data[lev]='\(';
        dfs(n, stk_top+1, lev+1);
        data[lev]='\)';
        dfs(n, stk_top-1, lev+1);
    }
}

int main(void)
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        dfs(n*2,-1,0);
        printf("\n");
    }
    return 0;
}
