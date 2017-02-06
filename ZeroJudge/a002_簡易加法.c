#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a,b,newa,newb;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		newa=((a&b)<<1);
		newb=(a^b);
		while((newa&newb))
		{
			a=((newa&newb)<<1);
			b=(newa^newb);
			newa=a;
			newb=b;
			
		}
		
		printf("%d\n",(((newa&newb)<<1)|(newa^newb)));
	}
		
	return 0;
}
