#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100002

typedef struct STACK
{
    int top;
    int bottom;
    int enti[STACK_SIZE];
}STK;

void init(STK*);
void pop(STK*);
void push(int, STK*);

int main(void)
{
    int term;
    int op, n;
    char temp[1000];
    STK stack;
    gets(temp);
    term = atoi(temp);
    init(&stack);
    while(term--)
    {
        gets(temp);
        sscanf(temp,"%d %d",&op, &n);
        if(op==2)//POP
        {
            pop(&stack);
        }
        else
        {
            push(n,&stack);
        }
    }

    return 0;
}

void init(STK *stack)
{
    stack->bottom = stack->top = 0;
}

void pop(STK *stack)
{
    if(stack->bottom == stack->top)
    {
        puts("empty!");
        return;
    }
    printf("%d\n",stack->enti[stack->top]);
    (stack->top)--;
}

void push(int n, STK *stack)
{
    stack->enti[ ++(stack->top)] = n;
}
