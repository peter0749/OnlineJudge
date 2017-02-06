#include <string.h>
#include <stdio.h>
#define MAX 1000001

int main(void)
{
    char input[MAX];
    int counter;
    int len;
    int i, j;
    while(scanf("%s",input)!=EOF)
    {
        len = strlen(input);
        for(i=0;i<len;i++)
        {
            counter=0;
            for(j=i; counter<len ;j++,counter++)
            {
                if(j>=len)j=0;
                putchar(input[j]);
            }
            putchar('\n');
        }
    }
    return 0;
}
