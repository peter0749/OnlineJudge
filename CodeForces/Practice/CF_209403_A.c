#include <stdio.h>
#include <stdlib.h>
#define MAXN 30
int main(void)
{
    int temp, sum;
    int term, i;
    while(scanf("%d", &term)!=EOF && term){
        sum = 0;
        for(i=0; i<term; ++i){
            scanf("%d", &temp);
            sum ^= temp;
        }
        printf(sum?"No\n":"Yes\n");
    }
    return 0;
}
