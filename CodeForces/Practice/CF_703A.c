#include <stdio.h>
#define MAX 110

int arr[MAX][2];
int count[2];

int main(void)
{
    int i,term;
    while(scanf("%d",&term)!=EOF)
    {
        for(i=0; i<term; i++)
            scanf("%d%d",&arr[i][0],&arr[i][1]);
        count[0] = count[1] = 0;
        for(i=0; i<term; i++)
        {
            if(arr[i][0]<arr[i][1])
                count[1]++;
            if(arr[i][0]>arr[i][1])
                count[0]++;
        }
        if(count[0]>count[1])printf("Mishka\n");
        else if(count[0]<count[1])printf("Chris\n");
        else printf("Friendship is magic!^^\n");
    }
    return 0;
}
