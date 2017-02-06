#include <stdio.h>
#include <stdlib.h>

//void initialize();
int throw_egg( int x );
//void answer( int x );

int arry[10001] = {0};

int main(void)
{
    int i;
    int left=1, right=9996;
    int flag;
    for(i=1;i<=999;i++) arry[i] = 1;
    while(right-left>1)
    {
        flag = (left+right) / 2;
        if(throw_egg(flag))
        {
            left = flag;
        }
        else
            right = flag;
    }
    printf("%d\n",left);


    return 0;
}

int throw_egg( int x )
{
    return arry[x];
}
