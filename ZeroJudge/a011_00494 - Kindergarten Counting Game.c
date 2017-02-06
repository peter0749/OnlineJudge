#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100000


int main(void)
{
	int count;
	int i; /*INDEX*/
	int founded=0;
	char str[MAX];
	while(gets(str)!=NULL)
	{
		count=0;
		for(i=0;i<strlen(str)+1;i++)
		{
			if( tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z')
			{
				founded=1;
			}
			else if(founded == 1)
			{
				count++;
				founded=0;
			}
		}
		printf("%d\n",count);
	}
	
	return 0;
}
