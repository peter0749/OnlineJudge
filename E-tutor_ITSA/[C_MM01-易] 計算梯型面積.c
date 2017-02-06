#include <stdio.h>  
#include <stdlib.h>  
  
int main(void)  
{  
    int up,low,h;  
    while(scanf("%d %d %d",&up,&low,&h)!=EOF)  
    {  
        printf("Trapezoid area:%.1lf\n",(double)(up+low)*h/2);  
    }  
    return 0;  
}  
