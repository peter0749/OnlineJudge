#include <stdio.h>  
#include <stdlib.h>  
  
int main(void)  
{  
    int n;  
    int i;  
    while(scanf("%d",&n)!=EOF)  
    {  
        for(i=1;i<=n;i++)  
            printf("%d*%d=%d\n",i,i,i*i);  
    }  
    return 0;  
}
