#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	int n=0,i;
	while(1)
	{
		i=1;
		scanf("%d",&n);
		if(n==0)	break;
		while(i<n)
		{
			if(i%7!=0)	printf("%d ",i);
			i++;
		}
		printf("\n");
	}
	
	return 0;
}
