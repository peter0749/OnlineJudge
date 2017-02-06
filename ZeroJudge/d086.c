#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	int sum = 0;
	char ch;
	while(1)
	{
		ch = getchar();
		if(ch == '\n')
		{
			printf("%d\n",sum);
			sum = 0;
		}
		else if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			sum += tolower(ch)-'a'+1;
		}
		else if(ch == '0')
		{
			ch = getchar();
			if(ch == '\n' || ch == EOF)
				exit(0);
			else
			{
				while(getchar()!='\n');
				puts("Fail");
				sum = 0;
			}
		}
		else
		{
			while((ch = getchar())!='\n');
			puts("Fail");
			sum = 0;
		}
	}

	return 0;
}
