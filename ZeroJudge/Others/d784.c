#include <stdio.h>
#include <stdlib.h>
#define MAX 200
#define INTMIN -2147483648

int dp[MAX];
int find_max(int data[], int n)
{
    int len=0;
    int i, j;
    int max = INTMIN;
    while(len<n)
    {
        for(i=0; i+len<n; i++)
        {
            dp[i]+=data[i+len];
            if(dp[i]>max)max=dp[i];
        }
        len++;
    }
    return max;
}

int main(void)
{
    int arr[MAX];
    int term;
    int n, i;
    scanf("%d", &term);
    while(term--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)dp[i]=0;
        for(i=0; i<n; i++)scanf("%d",arr+i);
        printf("%d\n",find_max(arr,n));
    }
    return 0;
}
