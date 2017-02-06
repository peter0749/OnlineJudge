#include <stdio.h>  
#include <stdlib.h>  
  
char bitmap[10][10];  
  
int main(void)  
{  
    int i, j, k;  
    int term, n;  
    for(i=0;i<10;i++)    for(j=0;j<10;j++)  
        scanf(" %c",&bitmap[i][j]);  
    scanf("%d",&term);  
    while(term--)  
    {  
        scanf("%d",&n);  
        for(k=0;k<n;k++)  
        {  
            scanf("%d %d",&i,&j);  
            putchar(bitmap[i][j]);  
        }  
        putchar('\n');  
    }  
  
    return 0;  
}  
