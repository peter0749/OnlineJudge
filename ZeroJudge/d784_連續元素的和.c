#include <stdio.h>
#include <stdlib.h>
#define MAX 600100
#define INF -2147483640
int arr[MAX];
int DP[MAX];

int main(void)
{
    int term, n, i, temp;
    int maxval=INF;
    scanf("%d",&term);
    while(term--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++){scanf("%d",&arr[i]);DP[i]=INF;}
        maxval = DP[0] = arr[0];
        for(i=1; i<n; i++)
        {
            DP[i] = (DP[i-1]<0) ? arr[i]:arr[i]+DP[i-1];
			if(DP[i]>maxval)maxval = DP[i];
        }
        printf("%d\n",maxval);
    }
    return 0;
}
