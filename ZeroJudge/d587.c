#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int first = 1;
	int term, i, j;
	int num[4]={0};
	while(scanf("%d",&term)!=EOF)
	{
		memset(num,0x00,sizeof(int)*4);
		first = 1;
		for(i=0;i<term;i++)
		{
			scanf("%d",&j);
			num[j]++;
		}
		for(i=1;i<=3;i++)
		{
			for(j=0;j<num[i];j++)
			{
				if(first == 1)
					first = 0;
				else
					printf(" ");
				printf("%d",i);
			}
		}
		printf("\n");
	}

	return 0;
}
