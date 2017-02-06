#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define ALPHANUM 500
#define MAXSTR 1000
typedef struct node{
	int val;
	struct node *lc, *rc;
}BST;
int stk[MAXSTR], top=0;

BST *__initNODE(){
	BST *new = (BST*)malloc(sizeof(BST));
	new->val = INT_MIN;
	new->lc = new->rc = NULL;
	return new;
}

void __push(int alpha, BST *head){
	if(alpha==INT_MIN) return;
	if(head->val==INT_MIN){
		head->val = alpha;
		return;
	}
	if(alpha < head->val  ){
		if(!head->lc) head->lc = __initNODE();
		__push(alpha, head->lc);
	}else{
		if(!head->rc) head->rc = __initNODE();
		__push(alpha, head->rc);
	}
}

void bst_postfix(BST *head){
	if(head==NULL)return;
	bst_postfix(head->lc);
	bst_postfix(head->rc);
	stk[top++] = head->val;
}

void del_bst(BST *head){
	if(head==NULL)return;
	del_bst(head->lc);
	del_bst(head->rc);
	head->val=0x00;
	head->lc = head->rc = NULL;
	free(head);
}

int main(void){
	BST *bst=NULL;
	char prefix[MAXSTR], infix[MAXSTR], postfix[MAXSTR];
	int term, i, counter[ALPHANUM];
	char temp[MAXSTR];
	fgets(temp,MAXSTR,stdin);
	term = atoi(temp);
	while(term--){
		memset(counter,0x00,sizeof(counter));
		memset(postfix,0x00,sizeof(postfix));
		bst = __initNODE();
		fgets(temp,MAXSTR,stdin);
		sscanf(temp,"%d %s %s",&i, prefix,infix);
		for(i=0 ; infix[i]!='\0'; ++i)	counter[infix[i]]=i;
		for(i=0 ; prefix[i]!='\0'; ++i) __push(counter[prefix[i]],bst);
		top = 0;
		bst_postfix(bst);
		for(i=0 ; i<top; ++i) postfix[i]=infix[stk[i]];
		fprintf(stdout,"%s\n",postfix);
		del_bst(bst);
		bst=NULL;
	}
	return 0;
}
