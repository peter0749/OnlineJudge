#include <stdio.h>
#include <stdlib.h>
#define MAX 101

	typedef struct rela{
		char name[MAX];
		int val;
	}REL;

void most_rel(REL*);

	int main(void)
	{
		int n;
		int i,j;
		while(scanf("%d",&n)!=EOF)
		{
			for(i=0;i<n;i++)
			{
				REL *data;
				data=(REL*)malloc(sizeof(REL)*10);
				for(j=0;j<10;j++)
				{
						scanf("%s %d",&((data+j)->name),&((data+j)->val));
						/*printf("%s %d\n",(data+j)->name,(data+j)->val);*/

				}
				printf("Case #%d:\n",i+1);
				most_rel(data);
				free(data);
			}
		}
		return 0;
	}


void most_rel(REL *data)
{
	int max;
	int i;
	REL *ptr;
	ptr=data;
	max=ptr->val;
	for(i=0;i<10;i++)
	{
		if((ptr+i)->val > max)
		{
			max=(ptr+i)->val;
		}
	}
	for(i=0;i<10;i++)
	{
		if((ptr+i)->val == max)
			printf("%s\n",(ptr+i)->name);
	}
}
