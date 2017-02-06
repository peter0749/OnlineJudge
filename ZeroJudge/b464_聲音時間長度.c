#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int i;
	double temp;
	int min,sec;
	int data;
	int rate,n;
	while(scanf("%d %d",&rate ,&n)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&data);
		temp = (double)n / rate;
		if(temp >= 60)
		{
			min = (int)temp / 60;
			sec = round(temp/60);
		}
		else
		{
			sec = round(temp);
			min = 0;
		}
		if(sec > 9)
			printf("%d:%d\n",min,sec);
		else 
			printf("%d:0%d\n",min,sec);

	}

	return 0;
}
