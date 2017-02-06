#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    while(scanf("%d",&i)!=EOF)
    {
	printf("%d\n", i<0 ? -i:i);
    }
    return 0;
}
