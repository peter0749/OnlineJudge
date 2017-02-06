#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int small_sqrt(int);

int main(void)
{
	double dl;
	long long int x;
	while(scanf("%lld",&x)!=EOF)
	{
		if(x < 134217728)
		{
			x = (long long int)(small_sqrt(8*(int)x+1) -1)/2;
			printf("%d\n",(int)x);
		}

		else
		{
			dl = (double)x;
			dl *= 8;
			dl++;
			dl = sqrt(dl);
			dl--;
			dl /= 2;
			printf("%d\n",(int)dl);	
		}
	}
	return 0;
}

int small_sqrt(int input)
{
	int i;
	for(i=1;i*i<=input;i++);
	return i;
}
