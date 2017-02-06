#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_t(long long int[3][2]);
void swap_t(long long int[3][2], int , int);
void waste_t(long long int[3][2]);

int main(void)
{
	int i;
	long long int cadi[3][2] = {0};
	while(scanf("%lld %lld %lld",&cadi[0][0], &cadi[1][0], &cadi[2][0]) > 2)
	{
		for(i=0;i<3;i++)
			cadi[i][1] = i;
		sort_t(cadi);	
		waste_t(cadi);
	}
	memset(cadi,0x00,sizeof(long long int)*3*2);
	return 0;
}

void sort_t(long long int arr[3][2])
{
	int i,j,min;
	for(i=0;i<2;i++)
	{
		min = i;
		for(j=i+1;j<3;j++)
		{
			if(arr[j][0]<arr[min][0])
				min = j;	
		}
		if(min != i)
		{
			swap_t(arr,min,i);
		}
		/*for(i=0;i<3;i++)
			printf("%c %d\n", arr[i][1]+'A' , arr[i][0]);
*/
	}	
}

void swap_t(long long int arr[3][2], int a, int b)
{
	int i;
   long long int temp; 
	for(i=0;i<2;i++)
	{
		temp = arr[a][i];
		arr[a][i] = arr[b][i];
		arr[b][i] = temp;
	}
}

void waste_t(long long int arr[3][2])
{
	long long int temp;
	if(arr[1][0] == arr[0][0])
	{
		printf("%c\n", arr[2][1]+'A');
	}
	else
	{
		temp = arr[0][0]+arr[1][0];
		if(temp > arr[2][0])
		{
			printf("%c\n", arr[1][1]+'A');
		}
		else
			printf("%c\n", arr[2][1]+'A');
	}
}
