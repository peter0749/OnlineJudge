#include <stdio.h>

int main(void)
{
    int i; /*INDEX*/
    int n;
    int a,b;
    while(scanf("%d",&n)!=EOF)
    {
	for(i=0;i<n;i++)
	{
	    scanf("%d %d",&a,&b);
	    printf(a>b ? ">": (a==b ? "=":"<"));
	    printf("\n");
	}
    }
    return 0;
}
