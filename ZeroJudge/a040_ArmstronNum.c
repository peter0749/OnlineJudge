#include <stdio.h>
#include <stdlib.h>

void print_arm(int a, int b);
int my_pow(int, int);
int my_log(int);

int main(void)
{
	int num1,num2;
	while(scanf("%d %d",&num1,&num2)!=EOF)
	{
		print_arm(num1,num2);
	}
	return 0;
}

void print_arm(int a, int b)
{
	int i,j,k,temp,temp1,none=1;
	for(i=a;i<=b;i++)
	{
		k=my_log(i)+1;
		temp1=i;
		int a[k];
		for(j=k-1;j>=0;j--)
		{
			a[j]=temp1/my_pow(10,j);
			temp1-=a[j]*my_pow(10,j);
			/*printf("a[%d]=%d\n",j,a[j]);*/

			temp+=my_pow(a[j],k);
		}
		if(temp==i)
		{
			none=0;
			printf("%d ",i);
		}
		temp=0;
	}
	/*printf("none=%d\n",none);*/
	if(none==1)	printf("none\n");
	else	printf("\n");
}

int my_pow(int a, int b)
{
	int temp = 1;
	int i;
	for(i=0;i<b;i++)
	{
		temp *= a;
	}
	return temp;
}

int my_log(int n)
{
	int i = 0;
	while(n > 9)
	{
		n /= 10;
		i++;
	}
	return i;

}
