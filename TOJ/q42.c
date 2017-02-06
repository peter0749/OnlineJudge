#include <stdio.h>
#include <stdlib.h>

int map[1003][1003] = {{0}};

void clrarr(int n)
{
    int i, j;
    for(i=0; i<1003; i++)
    {
        for(j=0; j<1003; j++)
            map[i][j] = -1;
    }
}

void prtout(int h, int w)
{
    int i, j;
    for(i=1; i<=h; i++)
    {
        for(j=1; j<=w; j++)
            printf("%3d ",map[i][j]);
        printf("\n");
    }
}

void des(int y, int x)
{
    if(map[y][x]!=0)    return;
    map[y][x] = 1;
    //prtout(4,4);
    //printf("\n");
    des(y,x+1);
    des(y,x-1);
    des(y+1,x);
    des(y-1,x);
    return;
}

int main(void)
{
    int term, w, h;
    int count;
    int i, j;
    char temp[1100];
    gets(temp);
    term = atoi(temp);
    while(term--)
    {
        count = 0;
        clrarr(-1);
        gets(temp);
        sscanf(temp,"%d %d",&h, &w);
        //printf("%d %d\n",h,w);
        for(i=0; i<h; i++)
        {
            gets(temp);
            for(j=0; j<w; j++)
            {
                if(temp[j]=='.')
                    map[i+1][j+1] = 0;
            }
        }
        //prtout(h,w);
        /*End of input*/
        for(i=1;i<=h;i++)
        {
            for(j=1;j<=w;j++)
            {
                if(map[i][j]==0)
                {
                    count++;
                    des(i,j);
                }
            }
        }
        //prtout(h,w);
        printf("%d\n",count);

    }
    return 0;
}
