#include <stdio.h>  
#include <stdlib.h>  
int main(void)  
{  
    int a,b;  
    while(scanf("%d %d",&a,&b)!=EOF)  
    {  
        printf("%d+%d=%d\n",a,b,a+b);  
        printf("%d*%d=%d\n",a,b,a*b);  
        printf("%d-%d=%d\n",a,b,a-b);  
        printf("%d/%d=%d...%d\n",a,b,a/b,a%b);  
    }  
    return 0;  
}  
