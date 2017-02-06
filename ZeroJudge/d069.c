#include <stdio.h>

int main(void)
{
	int year;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&year);
		printf((year%400==0 || (year%100!=0&&year%4==0)) ? "a leap year":"a normal year");
		if(n>0) printf("\n");
	}

	return 0;
}
