#include <stdio.h>
#include <stdlib.h>
#define QUE_LEN 100002

typedef struct QUE
{
    int bottom;
    int top;
    int enti[QUE_LEN];
}QUEUE;

void init(QUEUE *queue)
{
    queue->bottom = queue->top = 0;
}

void pop(QUEUE *queue)
{
    if(queue->top == queue->bottom)
    {
        puts("empty!");
        return;
    }
    printf("%d\n",queue->enti[ ++(queue->bottom)]);
}

void push(int n, QUEUE *queue)
{
    queue->enti[ ++(queue->top)] = n;
}

int main(void)
{
    int term;
    char temp[1000];
    QUEUE queue;
    int op, n;
    init(&queue);
    gets(temp);
    term = atoi(temp);
    while(term--)
    {
        gets(temp);
        sscanf(temp,"%d %d", &op, &n);
        if(op==2)//POP
        {
            pop(&queue);
        }
        else
        {
            push(n,&queue);
        }
    }
    return 0;
}
