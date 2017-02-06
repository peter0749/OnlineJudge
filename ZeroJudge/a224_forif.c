#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i=0;
    int n;
    long long int b,c;
    int a;
    while(scanf("%d",&n)!=EOF)
    {
	for(i=0;i<n;i++)
	{
	    scanf("%d %lld %lld",&a,&b,&c);
	    switch(a)
	    {
	    case 1:
                printf("%lld",b+c);
                break;
            case 2:
                printf("%lld",b-c);
                break;
            case 3:
                printf("%lld",b*c);
                break;
            case 4:
                printf("%lld",b/c);
                break;
            defaut:
                break;
	    }
	    printf("\n");

	}

    }
    return 0;
}
