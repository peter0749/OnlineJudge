#include <stdio.h>
#include <stdlib.h>
#define MAX 46342

char bitmap[MAX]={0};
int prime_list[5000]={0};

void mk_prime(void);
int is_prime(int);

int main(void)
{
	int input;
	mk_prime();
	while(scanf("%d",&input)!=EOF)
	{
		if(is_prime(input))
			printf("質數\n");
		else
			printf("非質數\n");
	}

	return 0;
}

void mk_prime(void)
{
	int i,j;
	int k = 0;
	for(i=3;i<MAX;i+=2)
	{
		if(bitmap[i]==0)
		{
			for(j=i+i;j<MAX;j+=i)
			{
				bitmap[j] = 1;
			}
			prime_list[k++] = i;
		}
	}
}

int is_prime(int n)
{
	int i;
	if(n == 2)
		return 1;
	else if(n%2==0)
		return 0;
	else if(n<46340)
	{
		return !bitmap[n];
	}
	else	/*n>=46340*/
	{
		for(i=0;prime_list[i]*prime_list[i]<=n && prime_list[i]!=0;i++)
		{
			if(n%prime_list[i]==0)
				return 0;
		}
		return 1;
	}
}
