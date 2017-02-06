#include <stdio.h>

int main(void)
{
    int count;
    int input;
    int comp_n;
    while(1)
    {
	scanf("%d",&input);
	if(input == 0)
	    break;
	count = 0;
	comp_n = 1;
	while(input & comp_n)
	{
	    comp_n = comp_n << 1;
	    count++;
	}
	printf("%d\n",count);
    }
    return 0;
}
