#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
#include <string.h>  
#define MAX 40  
  
void clean_up(int d[],int n)        /*清理*/  
{  
    int i;  
    for(i=0;i<n;i++)  
        d[i]=0;  
}  
  
void rev_n(int d[], int n)            /*反轉*/  
{  
    int i;  
    int temp;  
    for(i=0;i<n/2;i++)  
    {  
        temp = d[i];  
        d[i] = d[n-1-i];  
        d[n-1-i] = temp;  
    }  
}  
  
int b_add(int na, int nb,int a[],int b[], int c[])            /*大數加法，回傳結果的位數*/  
{  
    int i;  
    int more;  
    int nc;  
    nc = na>nb?na:nb;            /*找在加數，被加數裡找比較大的*/  
    for(i=0;i<nc;i++)  
    {  
        c[i] = a[i] + b[i];  
    }  
    for(i=0;i<nc;i++)  
    {  
        more = 0;  
                if(c[i]>=10)  
        {  
            c[i+1] += c[i]/10;  
            c[i] %= 10;  
            more = 1;                    /*是否出現過進位*/  
        }  
    }  
    nc += more;                                /*for 結束且 有進位 more == 1 else more == 0*/  
    return nc;                                    /*回傳結果的位數*/  
}  
  
int main(void)  
{  
    int term;  
    int a[MAX],b[MAX],c[MAX];  
    char temp[100];  
    char ch;  
    int i, j;  
    int na, nb, nc;  
    gets(temp);  
    term = atoi(temp);  
    while(term--)  
    {  
        clean_up(a,MAX);  
        clean_up(b,MAX);  
        clean_up(c,MAX);  
        gets(temp);  
        i = 0;  
        j = 0;  
        while(1)  
        {  
            ch = temp[i++];  
            if(ch==' '||ch=='\n'||ch=='\0')                /*檢查空格*/  
                break;  
            a[j++] = (ch-'0');                                        /*把數字寫到陣列裡*/  
        }  
        na = j;                                                                /*陣列 a 位數大小*/  
        rev_n(a,na);                                                    /*a反轉*/  
        j = 0;  
        while(1)  
        {  
            ch = temp[i++];  
            if(ch==' '||ch=='\n'||ch=='\0')  
                break;  
            b[j++] = (ch-'0');  
        }  
        nb = j;  
        rev_n(b,nb);  
                nc = b_add(na,nb,a,b,c);                                /*大數加法*/  
                /*下面是用來看陣列內容的*/  
#if 0  
        for(i=0;i<na;i++)  
            printf("%d : %d\n",i,a[i]);  
        for(i=0;i<nb;i++)  
            printf("%d : %d\n",i,b[i]);  
        for(i=0;i<nc;i++)  
            printf("%d : %d\n",i,c[i]);  
#endif  
          
        for(i=nc-1;i>=0;i--)                        /*倒著印*/  
            printf("%d",c[i]);  
        printf("\n");  
    }  
    return 0;  
}  
