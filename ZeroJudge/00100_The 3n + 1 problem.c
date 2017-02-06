#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int c_len[MAX+1] = {0};

int n(int i, int j)
{
	long long int k;
	int count, max=0;
	for(i;i<=j;i++)
	{
		if(c_len[i]!=0)
			count = c_len[i];
		else
		{
			count = 1;
			k = (long long int)i;
			while(k!=1)
			{
				if(k%2)
					k = 3*k+1;
				else
					k /= 2;
				if(k<=MAX && c_len[k]!=0)
				{
					count+=c_len[k];
					break;
				}
				count++;
			}
			c_len[i] = count;
		}
		if(max<c_len[i])
			max = c_len[i];
	}

	return max;
}

void swap(int *a, int *b)
{
	int temp;
	if(*a>*b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

int main(void)
{
	int i, j;
	n(1,MAX);
	while(scanf("%d%d",&i,&j)!=EOF)
	{
		if(i==0&&j==0)
			exit(0);
		printf("%d %d ",i,j);
		swap(&i,&j);
		printf("%d\n",n(i,j));
	}

	return 0;
}
