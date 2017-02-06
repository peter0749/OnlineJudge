#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#define MAX 10000  
  
void cp(char *, char *);  
  
int main(void)  
{  
    char p[MAX], q[MAX], r[MAX];  
    char *ptr = NULL;  
    int lengq,lengr;  
    int i;  
    int n;  
     
    while( (gets(p))!=NULL && (gets(q))!=NULL && (gets(r))!=NULL)  
    {  
        lengq = strlen(q);  
        lengr = strlen(r);  
        ptr = p;  
        while(ptr!=NULL)  
        {  
            ptr = strstr(ptr,q);  
            if(ptr!=NULL)  
            {  
                cp(ptr+lengq,ptr+lengr);  
                for(i=0; i<lengr && ptr!=NULL; i++,ptr++)  
                {  
                    *ptr = r[i];  
                }  
            }  
        }  
        puts(p);  
    }  
  
    return 0;  
}  
  
void cp(char *a, char *b)  
{  
    char temp[MAX];  
    strcpy(temp,a);  
    strcpy(b,temp);  
}  
