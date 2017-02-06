#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
int main(void)  
{  
    char temp[1000];  
    int k[200];  
    char *num;  
    int i;  
    while((fgets(temp,200,stdin))!=NULL)  
    {  
        i = 0;  
        num = strtok(temp," \n");  
        while(num != NULL)  
        {  
            k[i++] = atoi(num);  
            num = strtok(NULL," \n");  
        }  
        for(i=i-1;i>=1;i--)  
            printf("%d ",k[i]);  
        printf("%d\n",k[i]);  
    }  
    return 0;  
}  
