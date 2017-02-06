#include <stdio.h>  
#include <stdlib.h>  
  
int main(void)  
{  
    int input;  
    int i;  
    while(scanf("%d",&input)!=EOF)  
    {  
        for(i=128;i!=0;i>>=1)  
        {  
            printf(input&i ? "1":"0");  
        }  
        printf("\n");  
    }  
    return 0;  
}  
