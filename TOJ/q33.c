#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //freopen("getf.txt","w",stdout);
    int i;
    int f[31];
    f[0] = f[1] = 1;
    printf("1\n1\n");
    for(i=2;i<31;i++)
    {
        f[i] = f[i-1] + f[i-2];
        printf("%d\n",f[i]);
    }
    return 0;
}
