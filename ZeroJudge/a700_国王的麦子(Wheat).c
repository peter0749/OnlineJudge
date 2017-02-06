#include <stdio.h>

int main(void)
{
    int INDEX;
    int i,j;
    unsigned long long int val;
    while(scanf("%d %d",&i,&j)!=EOF)
    {
	val=1;
	for(INDEX=0;INDEX<8*(i)+(j)-9;INDEX++)
	{
	    val*=2;
	}
	printf("%llu\n",val);
    }
    return 0;
}
