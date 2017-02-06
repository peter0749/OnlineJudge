#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

typedef struct link
{
	struct WHATEVER *ptr;
	struct link *next;
}addr;

typedef struct WHATEVER
{
	int id, num;
	struct link *head, *tail;
}BOX;

BOX *boxaddr[100001];


int dfs(BOX *node)
{
	addr *foo = node->head;
	if(node->num>1)	return node->num;
	//printf("##%d\n",node->id);
	//getchar();
	while(foo!=NULL)
	{
		//puts("OOPS!");
		node->num += dfs(foo->ptr);
		foo = foo->next;
	}
	return node->num;
}

int main(void)
{
	int term, n, i, j, tar, src;
	int counter;
	addr *addrptr;
	scanf("%d",&term);
	while(term--)
	{
		counter = 0;
		scanf("%d %d", &n, &i);
		for(j=1;j<=n;j++)
		{
			boxaddr[j] = (BOX*)malloc(sizeof(BOX));
			boxaddr[j]->num = 1;
			boxaddr[j]->id = j;
			boxaddr[j]->head = boxaddr[j]->tail = NULL;
		}
		while(i--)
		{
			scanf("%d %d", &tar, &src);
			if(boxaddr[tar]->head==NULL)
			{
				boxaddr[tar]->head = (addr*)malloc(sizeof(addr));
				boxaddr[tar]->head->ptr = boxaddr[src];
				boxaddr[tar]->head->next = NULL;
				boxaddr[tar]->tail = boxaddr[tar]->head;
			}
			else
			{
				addrptr = (addr*)malloc(sizeof(addr));
				addrptr->ptr = boxaddr[src];
				addrptr->next = NULL;
				boxaddr[tar]->tail->next = addrptr;
				boxaddr[tar]->tail = boxaddr[tar]->tail->next;
				addrptr = NULL;
			}
		}
		for(j=1;j<=n;j++)
		{
			dfs(boxaddr[j]);
			//printf("~~%d\n",boxaddr[j]->num);
		}
		scanf("%d",&i);
		while(i--)
		{
			scanf("%d",&tar);
			printf("%d\n",boxaddr[tar]->num);
		}
		for(j=1;j<=n;j++)
		{
			if(boxaddr[j]!=NULL)
			{
				free(boxaddr[j]);
				boxaddr[j] = NULL;
			}
		}
	}
	return 0;
}


