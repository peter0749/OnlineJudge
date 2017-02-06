#include <stdio.h>
#include <stdlib.h>
#define MAX_L 10001
#define MAX_N 500

char str[MAX_N][MAX_L];

int main(void)
{
	int i = 0, j = 0;
	int founded = 0;
	while(gets(str[i++])!=NULL)
	{
		founded = 0;
		for(j=0;j<i-1;j++)
		{
			if(strcmp(str[i-1],str[j])==0)
			{
				founded = 1;
				puts("YES");
				break;
			}
		}
		if(founded == 0)	puts("NO");
	}
	return 0;
}
