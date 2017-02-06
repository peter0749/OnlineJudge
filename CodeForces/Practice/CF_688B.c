#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100100
int main(void)
{
    int i;
    char temp[MAX];
    while(scanf("%s",temp)!=EOF)
    {
        printf("%s",temp);
        for(i=strlen(temp)-1; i>=0; i--)
        {
            printf("%c",temp[i]);
        }
        printf("\n");
    }
    return 0;
}
