#include <stdio.h>  
#include <stdlib.h>  
  
int main(void)  
{  
    char temp[6];  
    int cm, i;  
    while((fgets(temp,6,stdin))!=NULL)  
    {  
        cm = 0;  
        for(i=0;i<3;i++)  
            cm += (temp[i]-'0')*(temp[i]-'0')*(temp[i]-'0');  
        if(cm == atoi(temp))  
            puts("Yes");  
        else  
            puts("No");  
    }  
    return 0;  
}  
