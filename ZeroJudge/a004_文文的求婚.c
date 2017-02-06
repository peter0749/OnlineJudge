#include <stdio.h>

int main(void)
{
    int year;
    int k;
    while(scanf("%d",&year)!=EOF)
    {
    k = (year % 400 == 0) || ((year% 4 == 0) && (year % 100 != 0));
    printf(k==0?"平年\n":"閏年\n");
    }
    return 0;
}
