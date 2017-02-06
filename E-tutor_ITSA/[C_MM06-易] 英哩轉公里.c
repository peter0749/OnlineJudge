#include <stdio.h>  
#include <stdlib.h>  
int main(void)  
{  
    int a;  
    double temp;  
    while(scanf("%d",&a)!=EOF)  
    {  
        temp = (double)a*1.6;  
        printf("%.1lf\n",temp);  
    }  
    return 0;  
}  
