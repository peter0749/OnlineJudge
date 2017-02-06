#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int count;
	int temp;
	int i,j; /*INDEX*/
	int num[3]={0};
	while(1)
	{
		count=0;
		for(j=0;j<5;j++){
		for(i=0;i<3;i++)
		{
			if(scanf("%d",&num[i])==EOF)
				exit(0);
		}
		for(i=0;i<2;i++)
		{
			if(num[i]>num[i+1])
			{
				temp=num[i];
				num[i]=num[i+1];
				num[i+1]=temp;
			}
		}
		if(num[0]+num[1]>num[2])
			count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
