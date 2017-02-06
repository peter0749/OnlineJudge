#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input;
	while(scanf("%d",&input)!=EOF)
	{
		if(0<=input && input<=10)	printf("%d\n",input*6);
		else if(10<input && input<=20)	printf("%d\n",60+(input-10)*2);
		else if(20<input && input<=40)	printf("%d\n",80+(input-20)*1);
		else printf("%d\n",100);
	}
	
	return 0;
}
