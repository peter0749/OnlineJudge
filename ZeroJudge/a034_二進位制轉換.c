#include <stdio.h>

int main(void)
{
	unsigned int i;
	unsigned int input;
	while(scanf("%u",&input)!=EOF)
	{
		for(i = 2147483648 ; !(i&input) && i!=0; i>>=1);
		for(i;i!=0;i>>=1)
			printf(input&i ? "1":"0");
		putchar('\n');
	}

	return 0;
}
