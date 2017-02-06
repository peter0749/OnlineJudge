#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long long int a,b;
	while(scanf("%lld%lld",&a,&b)==2)
	{
		printf("%lld\n",a>b ? a-b:b-a);
	}

	return 0;
}
