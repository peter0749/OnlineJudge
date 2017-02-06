#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i = 0;
	char line[100];
	char ch;
	long long int sum=0;
	while(1)
	{
		ch = getchar();
		if(ch == EOF)	break;
		else if(ch >= '0' && ch <= '9')
		{
			line[i++] = ch;
		}
		else if(ch == ' ' || ch == '\t' || ch == '\n')
		{
			line[i++] = '\0';
			sum += (long long int)atoi(line);
			i = 0;
		}
		if(ch == '\n')
		{
			printf("%lld\n", sum);
			sum = 0;
		}
	}

	return 0;
}
