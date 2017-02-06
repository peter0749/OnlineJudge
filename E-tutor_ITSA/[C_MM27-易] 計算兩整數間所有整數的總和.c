#include <stdio.h>  
#include <stdlib.h>  
  
int main(void)  
{  
    int a,b;  
    int i;  
    int sum;  
    while(scanf("%d %d",&a,&b)!=EOF)  
    {  
        sum = 0;  
        for(i=a;i<=b;i++)  
            sum += i;  
        printf("%d\n",sum);  
    }  
    return 0;  
}  
