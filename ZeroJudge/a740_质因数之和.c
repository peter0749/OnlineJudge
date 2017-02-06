#include <stdio.h>

int main(void)
{
    int sum=0;
    int input=0;
    int i; /*INDEX */
    while(scanf("%d",&input)!=EOF)
    {
        sum=0;
        while(input%2 == 0)
        {
            input/=2;
            sum+=2;
        }
        for(i=3; i*i<=input && input != 1; i+=2)
        {
            while(input%i == 0)
            {
                input/=i;
                sum+=i;
            }
        }
        if(input != 1)
        {
            sum+=input;
        }
        printf("%d\n",sum);
    }

    return 0;
}
