#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int T,i,j,temp;
	char str[11];
	while(1)
	{
		if(scanf("%d ",&T)==EOF)
			break;
		for(i=0;i<T;i++)
		{
			/*str=(char*)malloc(sizeof(char)*2147483647); */
			temp=1;
			gets(str);
			for(j=0;*(str+j)!='\0';j++)
			{
				temp*=(*(str+j)-'0');
			}
			printf("%d\n",temp);
			
		}	
	}
	/*free(str);*/
	return 0;
}
