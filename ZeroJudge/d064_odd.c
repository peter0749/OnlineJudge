#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input;
	while(scanf("%d",&input)!=EOF)
	{
		printf(input % 2 == 0 ? "Even\n":"Odd\n");
	}

	return 0;
}
