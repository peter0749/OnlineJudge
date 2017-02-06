#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count;
	unsigned int input;
	unsigned int i;
	while(1)
	{
		scanf("%u",&input);
		if(input==0)
			break;
		count = 0;
		printf("The parity of ");
		for(i=2147483648;i!=0&&!(input&i);i>>=1);
		for(i;i!=0;i>>=1)
		{
			if(i&input)
			{
				count++;
				putchar('1');
			}
			else
				putchar('0');
		}
		printf(" is %d (mod 2).\n",count);
	}

	return 0;
}
