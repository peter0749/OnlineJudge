#include <stdio.h>
#include <stdlib.h>

void sort(long long int*);
void q_sort(long long int*,int,int);
void fq_sort(double*,int,int);

int main(void)
{
	long long int r[3], temp;
	double a[3], ftemp;
	int n, i;
	scanf("%d",&n);
	while(n--)
	{
		temp = 0;
		scanf("%lld%lld%lld",&r[0],&r[1],&r[2]);
		if(r[0] > 1073741824 || r[1] > 1073741824 || r[2] > 1073741824)
		{
			for(i=0;i<3;i++)
				a[i] = (double)r[i];
			fq_sort(a,0,2);
			ftemp = a[0]*a[0] + a[1]*a[1] - a[2]*a[2];

			if(ftemp > 0)
				printf("acute triangle");
			else if(ftemp == 0)
				printf("right triangle");
			else
				printf("obtuse triangle");
		}
		else
		{
			q_sort(r,0,2);
			temp = r[0]*r[0] + r[1]*r[1] - r[2]*r[2];
			if(temp > 0)
				printf("acute triangle");
			else if(temp == 0)
				printf("right triangle");
			else
				printf("obtuse triangle");
		}
		if(n>0)
			printf("\n");
	}
	return 0;
}

void q_sort(long long int *ptr,int left,int right)
{
	int i,j;
	long long int pivot,temp;
	if(left<right)
	{
		i=left;
		j=right+1;
		pivot=*(ptr+left);
		do{
			do{
				i++;
			}while(*(ptr+i)<pivot);
			do{
				j--;
			}while(*(ptr+j)>pivot);
			if(i<j)
			{
				temp=*(ptr+i);
				*(ptr+i)=*(ptr+j);
				*(ptr+j)=temp;
			}
		}while(i<j);

		temp=*(ptr+left);
		*(ptr+left)=*(ptr+j);
		*(ptr+j)=temp;
		q_sort(ptr,left,j-1);
		q_sort(ptr,j+1,right);
	}

}

void fq_sort(double *ptr,int left,int right)
{
	int i,j;
	double pivot,temp;
	if(left<right)
	{
		i=left;
		j=right+1;
		pivot=*(ptr+left);
		do{
			do{
				i++;
			}while(*(ptr+i)<pivot);
			do{
				j--;
			}while(*(ptr+j)>pivot);
			if(i<j)
			{
				temp=*(ptr+i);
				*(ptr+i)=*(ptr+j);
				*(ptr+j)=temp;
			}
		}while(i<j);

		temp=*(ptr+left);
		*(ptr+left)=*(ptr+j);
		*(ptr+j)=temp;
		fq_sort(ptr,left,j-1);
		fq_sort(ptr,j+1,right);
	}

}
