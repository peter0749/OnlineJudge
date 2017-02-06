#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int sum = 0;
	char ch;
	while(1)
	{
		ch = getchar();
		if(ch==EOF)
			exit(0);
		else if(ch=='\n')
		{
			if(sum%3==0)
				printf("yes\n");
			else
				printf("no\n");
			sum = 0;
		}
		else if(ch>='1'&&ch<='9')
		{
			sum += (ch-'0');
		}
	}
	return 0;
}
