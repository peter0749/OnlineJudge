#include <stdio.h>
#include <stdlib.h>
#define MAX 10005

int DP[MAX] = {0};

int getmax(int left, int right)
{
    int max = 0, i ,j;
    long long int t;
    int step;

    for(i=left;i<=right;i++)
    {
        if(DP[i]!=0)
        {
            if(DP[i]>max) max = DP[i];
            continue;
        }
        else
        {
            step = 0;
            t = i;
            while(t!=1)
            {
                if(t%2)
                {
                    t = 3 * t + 1;
                }
                else
                {
                    t /= 2;
                }
                if(t<MAX&&DP[t]!=0)
                {
                    step+=DP[t];
                    break;
                }
                step++;
            }
            if(step>max)    max = step;
        }
    }
    return max;
}

int main(void)
{
    int term;
    int left, right;
    getmax(1,10000);
    scanf("%d",&term);
    while(term--)
    {
        scanf("%d %d",&left, &right);
        printf("%d\n",getmax(left,right));
    }
    return 0;
}
