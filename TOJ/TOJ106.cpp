#include <bits/stdc++.h>
#define MAXNODE 3001
#define MAXEDGE 1001
using namespace std;

typedef struct node
{
	bool visited;
	struct node *neighbor;
	struct node *nextnode;
}GRAPH;

GRAPH *nodes[MAXNODE];
GRAPH *tails[MAXNODE];

inline void pushback(int p, int q)
{
	GRAPH *ptr=NULL;
	ptr = new GRAPH;
	ptr->neighbor = nodes[q];
	ptr->nextnode = NULL;
	tails[p]->nextnode = ptr;
	tails[p] = ptr;
}

inline bool treversal(GRAPH *entry)
{
	GRAPH *ptr=entry;
	if(ptr!=NULL&&!ptr->visited)
	{
		do
		{
			ptr->visited = true;
			treversal(ptr->neighbor);
			ptr = ptr->nextnode;
		}while(ptr!=NULL&&!ptr->visited);
		return true;
	}
	return false;
}

int main(void)
{
	int term;
	int n, m;
	int p, q;
	int step(0);
	for(int i=0; i<MAXNODE; i++)tails[i] = nodes[i]=NULL;
	cin>>term;
	while(term--)
	{
		cin>>n>>m;
		for(int i=0; i<n; i++)
		{
			nodes[i] = new GRAPH;
			nodes[i]->neighbor = nodes[i]->nextnode = NULL;
			nodes[i]->visited=false;
			tails[i] = nodes[i];
		}
		for(int i=0; i<m; i++)
		{
			cin>>p>>q;
			pushback(p,q);
			pushback(q,p);
		}
		step = 0;
		for(int i=0; i<n; i++)
		{
			if(treversal(nodes[i]))step++;
		}
		cout<<step<<'\n';

		for(int i=0; i<n; i++)
		{
			delete nodes[i];
			nodes[i]=NULL;
			tails[i]=NULL;
		}
	}
	return 0;
}
