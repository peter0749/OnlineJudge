#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
#define ERR 0


typedef struct QUEUE
{
    int top;
    int bottom;
    int enti[100001];
} QUE; //Queue µ²ºc

QUE queue[MAX];

void prtque(QUE *queue)
{
    int i;
    if(queue->top==queue->bottom)   printf(" empty");
    else
    {
        while(queue->bottom!=queue->top)
        {
            printf(" %d",queue->enti[(queue->bottom)++]);
        }
    }
}

void init(int n, QUE *queue)
{
    queue->bottom = queue->top = 0;
    //queue->enti = (int*)malloc(sizeof(int)*(n+1));
}

/*
void destry(QUE *queue)
{
    free(queue->enti);
}
*/

int pop(QUE *queue)
{
    if(queue->top == queue->bottom) return 0;
    (queue->bottom)++;
    return 1;
}

void push(int n, QUE *queue)
{
    queue->enti[(queue->top)++] = n;
}

void join(QUE *q1, QUE *q2)
{
    while(q2->bottom!=q2->top)
    {
        q1->enti[ (q1->top)++] = q2->enti[ (q2->bottom)++ ];
    }
    q2->bottom = q2->top = 0;
}

int main(void)
{
    int n, m;
    int i, id, qid;
    char op[30];
    char temp[MAX];
    while(1)
    {
        gets(temp);
        if(sscanf(temp,"%d %d",&n, &m)<2)   return 0;
        for(i=1; i<=n; i++)
        {
            init(m,&queue[i]);
        }
        while(m--)
        {
            gets(temp);
            sscanf(temp,"%s %d %d",op, &qid, &id);

            if(strncmp(op,"ADD",3)==0)
            {
                push(id,&queue[qid]);
            }
            else if(strncmp(op,"LEAVE",5)==0)
            {
                if(pop(&queue[qid])==0)  printf("queue %d is empty!\n",qid);
            }
            else
            {
                join(&queue[id], &queue[qid]);
            }
        }

        for(i=1; i<=n; i++)
        {
            printf("queue %d:",i);
            prtque(&queue[i]);
            printf("\n");
            //destry(&queue[i]);
        }
    }
    return 0;
}
