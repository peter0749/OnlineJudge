#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
int main(void)  
{  
    char data[21];  
    int term;  
    int i;  
    scanf("%d",&term);  
    while(term--)  
    {  
        scanf("%s",data);  
        for(i=strlen(data)-1;i>=0;i--)  
        {  
            if(data[i]>='a'&&data[i]<='z')  
                putchar(toupper(data[i]));  
            else if(data[i]>='A'&&data[i]<='Z')  
                putchar(tolower(data[i]));  
            else putchar(data[i]);  
        }  
        putchar('\n');  
    }  
    return 0;  
}  
