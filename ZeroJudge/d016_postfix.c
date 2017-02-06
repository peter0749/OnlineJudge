#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SMP strcmp
#define MAX 1000

int main(void)
{
	char *tok = " ,;\t\n";
	int num[MAX];
	char temp[MAX];
	//char str_stack[MAX][10];
	char *ptr = NULL;
	int s_count = 0;
	while((gets(temp))!=NULL)
	{
		s_count = 0;
		ptr = strtok(temp,tok);
		while(ptr!=NULL)
		{
			if(SMP(ptr,"+")==0)
			{
				//printf("==== %d %d\n",num[s_count-2],num[s_count-1]);
				num[s_count-2] = num[s_count-2]+num[s_count-1];
				s_count--;
			}
			else if(SMP(ptr,"-")==0)
			{
				num[s_count-2] = num[s_count-2]-num[s_count-1];
				s_count--;
			}
			else if(SMP(ptr,"*")==0)
			{
				num[s_count-2] = num[s_count-2]*num[s_count-1];
				s_count--;
			}
			else if(SMP(ptr,"/")==0)
			{
				num[s_count-2] = num[s_count-2]/num[s_count-1];
				s_count--;
			}
			else if(SMP(ptr,"%")==0)
			{
				num[s_count-2] = num[s_count-2]%num[s_count-1];
				s_count--;
			}
			else if(SMP(ptr,"^")==0)
			{
				num[s_count-2] = pow(num[s_count-2],num[s_count-1]);
				s_count--;
			}
			else
			{
				num[s_count++] = atoi(ptr);
			}
			ptr = strtok(NULL,tok);
		}
		printf("%d\n",num[0]);
	}
	
	return 0;
}
