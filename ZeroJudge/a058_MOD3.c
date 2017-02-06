#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n,i=0,temp,k0,k1,k2;
	while(scanf("%d",&n)!=EOF)
	{
		k0=k1=k2=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			temp%=3;
			switch(temp)
			{
				case 1:
					k1++;
					break;
				case 2:
					k2++;
					break;
				default:
					k0++;
					break;
			}
		}
		printf("%d %d %d\n",k0,k1,k2);
	}
	
	return 0;
}
