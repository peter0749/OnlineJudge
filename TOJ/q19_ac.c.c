#include <stdio.h>
#include <stdlib.h>
#define S_EMPTY -9999
#define MAX 100001

typedef struct STACK
{
    int top;
    int enti[MAX];
} STK;

int compose(const int n, const int test[]);
int f_solution(int n, const int test[]);
void push(int n, STK *stack);
int pop(STK *stack);
void S_enum(int n, STK *stack);      /*Only at first time*/
void init(STK *stack);

STK src, buffer, tar;//Declare the stacks

int main(void)
{
    int term;
    int n, i;
    int test[MAX];

    scanf("%d",&term);
    while(term--)
    {
        scanf("%d",&n);

        for(i=1; i<=n; i++)
        {
            scanf("%d",&test[i]);
        }
        printf(f_solution(n,test)?"Yes\n":"No\n");
    }
    return 0;
}

void init(STK *stack)
{
    stack->top = 0;
}

void S_enum(int n, STK *stack)      /*Only at first time*/
{
    int i;
    for(i=n; i>=1; i--)
    {
        stack->enti[ ++(stack->top)] = i;
    }
}

int pop(STK *stack)
{
    int res;
    res = stack->enti[stack->top];
    (stack->top)--;
    return res;
}

void push(int n, STK *stack)
{
    stack->enti[ ++(stack->top)] = n;
}

int f_solution(int n, const int test[])
{
    init(&src);
    S_enum(n,&src);
    init(&buffer);
    init(&tar);
    /*End of initialization*/

    return compose(n,test);
}

int compose(const int n, const int test[])
{
    int i;
    if(tar.top > 0 && test[tar.top]!=tar.enti[tar.top]) return 0;     /*Tar is not empty, and not Founded, Quit*/
    if(tar.top == n && test[tar.top]==tar.enti[tar.top]) return 1;/*a solution*/
    if(src.top == 0) /*If src is empty, no more branch*/
    {
        i = 0;
        while(buffer.top && test[tar.top]==tar.enti[tar.top])
        {
            push(pop(&buffer),&tar);
            i++;
        }

        if(n==tar.top && test[tar.top]==tar.enti[tar.top])  return 1;

        while(i--)
        {
            push(pop(&tar),&buffer);      /*Push back*/
        }
        return 0;
    }

    if(buffer.top == 0)
    {
        push(pop(&src),&buffer);
        if(compose(n,test))/*Recursively find solutions, only one branch*/
            return 1;
        else
        {
            push(pop(&buffer),&src);
            return 0;
        }
    }
    else
    {
        push(pop(&buffer),&tar);   /*Left branch, pop from buffer to tar*/
        if(compose(n,test))
        {
            return 1;//Founded
        }
        //Not Founded
        push(pop(&tar),&buffer);/*Push back*/

        push(pop(&src),&buffer);/*Right branch, pop from src to buffer*/
        if(compose(n,test))
            return 1;
        push(pop(&buffer),&src);/*Push back*/
        /*Recursively find solutions, two branchs*/
        return 0;
    }
}
