#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i;
    int sum;
    char num[1001];
    while(1)
    {
	sum=0;
	gets(num);
	if(num[0]=='0')
	    break;
	for(i=0;i<strlen(num);i+=2)
	{
	    sum+=(num[i]-'0');
	}
	for(i=1;i<strlen(num);i+=2)
	{
	    sum-=(num[i]-'0');
	}
	if(sum % 11 == 0 )
	    printf("%s is ",num);
	else
	    printf("%s is not ",num);
	printf("a multiple of 11.\n");
    }
    return 0;
}
