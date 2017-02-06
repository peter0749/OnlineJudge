#include <stdio.h>
#include <stdlib.h>
#define MAX 106
char visited[MAX];
int node[MAX][MAX];
int counter=0;

void dfs(const int n)
{
    int i;
    visited[n]=1;
    counter++;
    for(i=1;i<=node[n][0];i++)
    {
        if(!visited[node[n][i]])
        {
            dfs(node[n][i]);
        }
    }
}

int main(void)
{
    int n, d[MAX], i, e, x;
    int max,min,m_index;
    while(scanf("%d",&n)!=EOF&&n)
    {
        node[0][0]=n;
        for(i=1;i<=n;i++)
        {
            d[i]=0;
            node[i][0]=0;
            scanf("%d",&e);
            while(e--)
            {
                scanf("%d",&x);
                node[i][++node[i][0]] = x;
            }
        }
        max = -1; min = 1;
        for(i=1;i<=n;i++)
        {
            memset(visited,0,sizeof(char)*(n+1));
            counter=0;
            dfs(i);
            d[i]=counter;
        }
        for(i=1;i<=n;i++)
        {
            if(d[i]>max)max=d[i];
        }
        i=1;
        while(d[i]!=max)i++;
        printf("%d\n",i);
    }
    return 0;
}
