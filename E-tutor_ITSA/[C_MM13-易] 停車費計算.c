#include <stdio.h>  
#include <stdlib.h>  
  
int main(void)  
{  
    int sum;  
    int a,b,c,d;  
    while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF)  
    {  
        sum = (c*60+d) - (a*60+b);  
        sum /= 30;  
        if(sum<=4)  
            printf("%d\n",sum*30);  
        else if(sum<=8)  
        {  
            sum-=4;  
            printf("%d\n",120+sum*40);  
        }  
        else  
        {  
            sum-=8;  
            printf("%d\n",280+sum*60);  
        }  
    }  
    return 0;  
}  
