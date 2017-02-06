#include <stdio.h>

int main(void)
{
	unsigned int n;
	unsigned long long int temp;
	while(scanf("%d",&n)!=EOF)
	{
		temp=n*(n+1);
		printf("%llu %llu\n",temp>>1,(temp*(n+2))/6);
	}
	
	return 0;
}
