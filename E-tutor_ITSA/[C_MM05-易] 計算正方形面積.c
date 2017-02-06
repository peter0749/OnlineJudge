#include <stdio.h>  
#include <stdlib.h>  
int main(void)  
{  
    double a;  
    int temp;  
    while(scanf("%lf",&a)!=EOF)  
    {  
        temp = a*a*100;  
        temp += 5;  
        a = (double)temp/100;  
        printf("%.1lf\n",a);  
    }  
    return 0;  
}  
