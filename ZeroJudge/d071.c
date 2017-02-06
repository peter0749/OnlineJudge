#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input;
	while(scanf("%d",&input)!=EOF)
	{
		printf(input%400==0 || (input%100!=0 && input%4==0) ? "a leap year\n":"a normal year\n");
	}

	return 0;
}
