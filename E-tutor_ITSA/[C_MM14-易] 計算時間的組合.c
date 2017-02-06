#include <stdio.h>  
#include <stdlib.h>  
  
int main(void)  
{  
    int sec;  
    while(scanf("%d",&sec)!=EOF)  
    {  
        printf("%d days\n",sec/(24*60*60));  
        sec %= (24*60*60);  
        printf("%d hours\n",sec/(60*60));  
        sec %= (60*60);  
        printf("%d minutes\n",sec/60);  
        sec %= 60;  
        printf("%d seconds\n",sec);  
    }  
    return 0;  
}  
