#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
	int key;
	struct node *l, *r;
}BST;

BST *push(BST *head,int num)
{
	BST *ptr;
	if(head==NULL)
	{
		head = new BST;
		head->l = head->r = NULL;
		head->key = num;
	}
	else if(num<head->key)
	{
		if(head->l==NULL)
		{
			ptr = new BST;
			ptr->l = ptr->r = NULL;
			ptr->key = num;
			head->l = ptr;
		}
		else
			push(head->l,num);
	}
	else
	{
		if(head->r==NULL)
		{
			ptr = new BST;
			ptr->l = ptr->r = NULL;
			ptr->key = num;
			head->r = ptr;
		}
		else
			push(head->r,num);
	}
	return head;
}

void travel(BST *head)
{
	if(head==NULL)	return;
	cout<<' '<<head->key;
	travel(head->l);
	travel(head->r);
	delete head;
}

int main(void)
{
	cin.sync_with_stdio(false);
	int term,num;
	BST *head=NULL;
	while(cin>>term)
	{
		while(term--)
		{
			cin>>num;
			head = push(head,num);
		}
		cout<<head->key;
		travel(head->l);
		travel(head->r);
		cout<<'\n';
		delete head;
		head = NULL;
	}
}
