#include <stdio.h>
#include <stdlib.h>

void solve(int N,int order[]);
void push_train(){}
void move_station_1_to_2(){}
void move_station_2_to_1(){}
void pop_train(){}
void no_solution(){}

int main(void)
{
    return 0;
}


void solve(int N,int order[])
{
    int i, j, top = N, flag;
    int stack[5001] = {0};
    for(i=1;i<=N;i++)//Load the stack into station
    {
        stack[i] = i;
        push_train();
        move_station_1_to_2();
    }

    for(i=0;i<N;i++)//Pop the Nth cargo(???
    {
        for(j=top;j>=1;j--)
        {
            if(stack[j]==order[i])
            {
                flag = j;
                break;
            }
        }
        for(j=top;j>flag;j--)
        {
            move_station_2_to_1();
        }
        pop_train();

        for(j=top;j>flag;j--)
        {
            move_station_1_to_2();
        }

        for(j=flag;j<top;j++)
        {
            stack[j] = stack[j+1];
        }
        top--;
    }
}
