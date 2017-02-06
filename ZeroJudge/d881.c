#include <stdio.h>

int main(void)
{
	/*
	int i;
	int sum;*/
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		/*
		sum = 0;
		
		for(i=1;i<=50;i++)
		{
			sum += 1 + ((2+n*(i-2))*(i-1)/2);

		}
		*/
		/*printf("%d\n",sum);*/

		printf("%d\n", 50 + (((n*42925)+(2-3*n)*1275+50*(2*n-2))/2));

	}
	return 0;
}
