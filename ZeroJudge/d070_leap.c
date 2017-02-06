#include <stdio.h>

int main(void)
{
	int input;
	while(1)
	{
		scanf("%d",&input);
		if(input == 0)
			break;
		printf(input%400==0||input%100!=0&&input%4==0?"a leap year\n":"a normal year\n");
	}

	return 0;
}
