#include <stdio.h>  
#include <stdlib.h>  
  
int is_per(int n);  
void swap(int *a, int *b)  
{  
    int temp;  
    if(*a>*b)  
    {  
        temp = *a;  
        *a = *b;  
        *b = temp;  
    }  
}  
  
int main(void)  
{  
    //freopen("testout.txt","w",stdout);  
    int ok;  
    int i, j, a, b;  
    while(scanf("%d%d",&a,&b)!=EOF)  
    {  
        ok = 0;  
        swap(&a,&b);  
        for(i=a;i<=b;i++)  
        {  
            if(is_per(i))  
            {  
                if(ok==0)  
                    ok = 1;  
                else  
                    printf(" ");  
                printf("%d",i);  
            }  
        }  
        if(ok==0)  
            printf("null");  
        printf("\n");  
    }  
    return 0;  
}  
  
int is_per(int n)  
{  
    int temp = 0;  
    int i, j;  
    for(i=1;i<n;i++)  
    {  
        if(n%i==0)  temp+=i;  
    }  
    if(temp==n) return 1;  
    return 0;  
}  
