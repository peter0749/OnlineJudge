#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100000000
bool nums[MAX]= {false};
void mk_prime(void);
void count_prime(int, int);

int main(void)
{
    int a, b;
    mk_prime();
    while(scanf("%d %d",&a, &b)!=EOF)
    {
        count_prime(a,b);
    }
    return 0;
}

void mk_prime(void)
{
    int i, j;/*INDEX*/

    nums[0]=true;   /*0 is not a num. of prime.*/
    nums[1]=true;   /*1 is not a num. of prime*/
    for(i=3; i*i<=MAX; i+=2)	/*Generate a prime list.*/
    {
        if(nums[i] == false)
        {
            for(j=i+i; j<MAX; j+=i) /*Eliminate all multiple of i.*/
            {
                nums[j] = true;
            }
        }
    }
}

void count_prime(int a, int b)
{
    int i;
    int count=0;
    if(a<=2 && b>=2)
        count=1;
    if(a % 2 ==0)
        a++;
    for(i=a; i<=b; i+=2)
    {
        if(nums[i] == false)
            count++;
    }
    printf("%d\n",count);
}
