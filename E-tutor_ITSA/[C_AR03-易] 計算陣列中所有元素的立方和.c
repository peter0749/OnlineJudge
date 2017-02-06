#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
int main(void)  
{  
    char temp[1000];  
    char *num;  
    int sum = 0;  
    int ccc = 0;  
    while((fgets(temp,200,stdin))!=NULL)  
    {  
        sum = 0;  
        num = strtok(temp," \n");  
        while(num != NULL)  
        {  
            ccc = atoi(num);  
            sum += ccc*ccc*ccc;  
            num = strtok(NULL," \n");  
        }  
        printf("%d\n",sum);  
    }  
    return 0;  
}  
