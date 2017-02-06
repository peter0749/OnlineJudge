#include <stdio.h>

int main(void)
{
	double input;
	while(scanf("%lf",&input)!=EOF)
	{
		printf("%.3lf\n",(input-32)*5/9);
	}

	return 0;
}
