#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bitmap[1001], pri_list[170]={0},prt_list[1001]={0};

void mk_prime(void);


int main(void)
{
	memset(bitmap,0x01,sizeof(int)*1001);
	pri_list[0] = 2;
	mk_prime();
	int first;
	int n;	/*n for input*/
	int i; /*i for INDEX*/
	while(scanf("%d",&n)!=EOF)
	{
		first = 1;
		for(i=0;i<=170;i++)
		{
			if(pri_list[i] != 0)
			{
				while(n%pri_list[i] == 0)
				{
					n /= pri_list[i];
					prt_list[pri_list[i]]++;
				}
			}
		}
		for(i=2;i<=1000;i++)
		{
			if(prt_list[i] != 0)
			{
				if(first == 0)
					printf(" * ");
				first = 0;
				printf("%d",i);
				if(prt_list[i] > 1)
					printf("^%d",prt_list[i]);
			}
		}
		if(n != 1)
		{
			if(first == 1)
				printf("%d",n);
			else
				printf(" * %d",n);
		}
		printf("\n");
		memset(prt_list,0x00,sizeof(int)*1001);
	}

	return 0;
}

void mk_prime(void)
{
	int count = 1;
	int i, j;
	for(i=3;i*i<=1000;i+=2)
	{
		if(bitmap[i])
		{
			for(j=i+i;j<=1000;j+=i)
				bitmap[j] = 0;
			pri_list[count++] = i;
		}
	}
	for(i=31;i<=1000;i+=2)
	{
		if(bitmap[i])
			pri_list[count++] = i;
	}
#if 0
	for(i=0;i<count;i++)
	{
		printf("%3d\n",pri_list[i]);
	}
	printf("%d\n",count);
#endif
}
