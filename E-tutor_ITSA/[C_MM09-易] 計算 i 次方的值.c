#include <stdio.h>  
#include <stdlib.h>  
  
int main(void)  
{  
    int i;  
    unsigned int base = 1;  
    while(scanf("%d",&i)!=EOF)  
    {  
        base = 1;  
        if(i<=31)  
        {  
            base <<= i;  
            printf("%u\n",base);  
        }  
        else  
            printf("Value of more than 31\n");  
    }  
  
    return 0;  
}  
