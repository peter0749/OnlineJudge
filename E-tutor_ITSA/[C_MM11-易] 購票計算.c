#include <stdio.h>  
#include <stdlib.h>  
  
int main(void)  
{  
    int input;  
    while(scanf("%d",&input)!=EOF)  
    {  
        printf("NT10=%d\n",input/10);  
        input %= 10;  
        printf("NT5=%d\n",input/5);  
        input %= 5;  
        printf("NT1=%d\n",input);  
    }  
    return 0;  
}  
