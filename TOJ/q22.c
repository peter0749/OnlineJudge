#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001

int com(int n);      //Compare func prototype
int bro[MAX] = {0};

int main(void)
{
    int term, n, i;
    scanf("%d",&term);
    while(term--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&bro[i]);
        }
        printf("%d\n",com(n));

    }

    return 0;
}

int com(int n)       //Comp Func Itself
{
    int counter = 0;
    int max;
    int i, j;
    for(i=0;i<n-1;i++)      //Bro[i] as the global maxima
    {
        max = -999;         //max as the local maxima
        for(j=i+1;j<n;j++)
        {
            if(max>bro[i])   break;
            else if(bro[j]<max) continue;
            else
            {
                if(bro[j]>max) max = bro[j];
                counter++;
            }
        }
    }
    return counter;
}
