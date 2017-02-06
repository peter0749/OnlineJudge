#include <stdio.h>
#include <stdlib.h>

int get_GCD(int, int);

int main(void)
{
	int a, b;
	while(scanf("%d%d",&a,&b)==2)
	{
		printf("%d\n",get_GCD(a,b));
	}
	return 0;
}

int get_GCD(int a, int b)
{
	return a%b ? get_GCD(b,a%b):b;
}
