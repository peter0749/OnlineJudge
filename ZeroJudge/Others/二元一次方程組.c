#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a,b,c,d,e,f, detA, detB, detC;
    while(scanf("%d%d%d%d%d%d",&a,&b,&e,&c,&d,&f)!=EOF)
    {
        detC = a*d-b*c;
        detA = e*d-b*f;
        detB = a*f-e*c;
        if(detC==0)
        {
            if(detA==0&&detB==0)printf("Too many\n");
            else    printf("No answer\n");
        }
        else
            printf("x=%.2lf\ny=%.2lf\n",((double)detA/(double)detC),((double)detB/(double)detC));
    }
    return 0;
}
