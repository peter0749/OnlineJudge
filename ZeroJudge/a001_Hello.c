#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char fstr[10];
	while(fgets(fstr,10,stdin)!=NULL)
	{
		putchar('h');putchar('e');putchar('l');putchar('l');putchar('o');putchar(',');putchar(' ');
		fputs(fstr,stdout);
	}
	return 0;
}
