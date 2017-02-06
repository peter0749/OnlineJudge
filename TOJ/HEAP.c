#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

void swap(int *dead, int *beef)
{
    int temp;
    temp = *dead;
    *dead = *beef;
    *beef = temp;
}

void push(int *n, int heap[], int key)
{
    int i;
    int pa;
    heap[++(*n)] = key;
    if(*n==0)   return;
    i = *n;
    while(i>0)
    {
        pa = (i-1)/2;
        if(heap[i]<=heap[pa])
        {
            swap(&heap[i],&heap[pa]);
            i = pa;
        }
        else
            return;
    }
}

int top(int n, int heap[])
{
    if(n<0) return -1;
    return heap[0];
}

void pop(int *n, int heap[])
{
    int child=0,i=0;
    if(*n==-1) return;

    heap[0] = heap[(*n)--];
    while((child=i*2+1)<=*n)
    {
        if(child+1<=*n&&heap[child]>heap[child+1])   child+=1;
        if(heap[i]>heap[child])
        {
            swap(&heap[i],&heap[child]);
            i = child;
        }
        else return;
    }
}

int main(void)
{
    int heap[MAX];
    int n=-1;
    //int i;
    int term;
    int op;
    scanf("%d",&term);
    while(term--)
    {
        scanf("%d",&op);
        if(op==1)
        {
           scanf("%d",&op);
           push(&n,heap,op);
           //for(i=0; i<=n; i++)printf("^%d\n",heap[i]);
        }
        else
        {
            if(n<0)puts("empty!");
            else
            {
                printf("%d\n", top(n,heap));
                pop(&n,heap);
                //for(i=0; i<=n; i++)printf("^%d\n",heap[i]);
            }
        }
    }
    return 0;
}
