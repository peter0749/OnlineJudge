#include <stdio.h>  
#include <stdlib.h>  
  
int main(void)  
{  
    int low,h;  
    while(scanf("%d %d",&low,&h)!=EOF)  
    {  
        printf("%.1lf\n",(double)(low)*h/2);  
    }  
    return 0;  
}  
