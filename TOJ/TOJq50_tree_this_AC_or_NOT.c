#include <stdio.h>
#include <stdlib.h>

typedef struct LINKS
{
	struct NODES *addr;
	struct LINKS *next;
}link;

typedef struct NODES
{
	int num;
	struct LINKS *head, *tail;
}node;

node *nodeset[100000];

void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void push(int tar, int src)
{
	link *tobeadd;
	if(nodeset[tar]->head==NULL)
	{
		nodeset[tar]->head = (link*)malloc(sizeof(link));
		nodeset[tar]->head->addr = nodeset[src];
		nodeset[tar]->head->next = NULL;
		nodeset[tar]->tail = nodeset[tar]->head;
	}
	else
	{
		tobeadd = (link*)malloc(sizeof(link));
		tobeadd->addr = nodeset[src];
		tobeadd->next = NULL;
		nodeset[tar]->tail->next = tobeadd;
		nodeset[tar]->tail = nodeset[tar]->tail->next;
	}
}

int dfs(node *ptr)
{
	link *nodeaddr;
	if(ptr->head==NULL)	return 1;//Leaves
	if(ptr->num > 1)//Has been modified
	{
		return ptr->num;
	}
	nodeaddr = ptr->head;
	while(nodeaddr!=NULL)
	{
		ptr->num += dfs(nodeaddr->addr);
		nodeaddr = nodeaddr->next;
	}
	return ptr->num;
}

void destroy(node *target)
{
	link *ptr1, *ptr2;
	ptr1 = target->head;
	while(ptr1!=NULL)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
		free(ptr2);
	}
	free(target);
}

int main(void)
{
	int term;
	int n, i;
	int tar, src;
	scanf("%d", &term);
	while(term--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			nodeset[i] = (node*)malloc(sizeof(node));
			nodeset[i]->head = nodeset[i]->tail = NULL;
			nodeset[i]->num = 0;
		}
		nodeset[0]->num = 1;
		for(i=0;i<n-1;i++)
		{
			scanf("%d %d", &tar, &src);
			if(nodeset[src]->num == 1)	swap(&tar,&src);
			push(tar,src);
			nodeset[src]->num = 1;
		}

		for(i=0;i<n;i++)
		{
			printf("node %d: %d\n", i, dfs(nodeset[i]));
		}

		for(i=0;i<n;i++)
		{
			destroy(nodeset[i]);
		}
	}
	return 0;
}
