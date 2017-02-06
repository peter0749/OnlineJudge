#include <stdio.h>
#include <stdlib.h>
#define MAX 7
#define LEN MAX+1

void print_out_num(char*);

int main(void)
{
	int i;
	char input[LEN];
	while(scanf("%s",&input)!=EOF)
	{
		for(i=0;i<MAX-1;i++)
		{
			print_out_num(input+i);
		}
		printf("\n");
	}
	
	return 0;
}

void print_out_num(char *input)
{
	char *ptr;
	ptr=input;
	if(*(ptr)>*(ptr+1))
	{
		printf("%d",*(ptr)-*(ptr+1));
	}
	else if(*(ptr)<*(ptr+1))
	{
		printf("%d",*(ptr+1)-*(ptr));
	}
	else
	{
		printf("0");
	}
}
