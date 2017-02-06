#include <stdio.h>
#include <stdlib.h>

int pass_or_not(int,int*);

int main(void)
{
	int n,i,pon;
	int *score_str;
	while(scanf("%d",&n)!=EOF)
	{
		score_str=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
			scanf("%d",score_str+i);
		}
	pon=pass_or_not(n,score_str);
	if(pon==0)
		printf("no\n");
	else
		printf("yes\n");	
	}
	
	return 0;
}

int pass_or_not(int n,int *ptr)
{
	int i;
	float temp=0;
	for(i=0;i<n;i++)
	{
		temp+=*(ptr+i);
	}
	temp/=n;
	if(temp>59)
		return 0;
	else
		return 1;
}
