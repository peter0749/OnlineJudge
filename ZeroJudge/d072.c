#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input;
	int n;
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&input);
		printf(input%400==0||input%100!=0&&input%4==0 ? "Case %d: a leap year\n":"Case %d: a normal year\n",i);
	}

	return 0;
}
