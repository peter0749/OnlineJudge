#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 106
#define EMPTY -9999

int map[MAX][MAX];

typedef struct COD
{
	int y, x;
	int step;
}CO;

typedef struct QUEUE
{
	int top , bottom;
	CO q[10009];
}QUE;

QUE queue;

void push(CO cord, QUE *queue)
{
	queue->q[queue->top] = cord;
	queue->top++;
}

CO pop(QUE *queue)
{
	CO cord;
	cord.x = cord.y = EMPTY;
	if(queue->top == queue->bottom )
		return cord;
	cord = queue->q[queue->bottom];
	queue->bottom++;
	return cord;
}

int bfs(CO mew)
{
	int i = 0;
	CO temp;

	push(mew,&queue);
	
	while(queue.top!=queue.bottom)
	{
		//for(i=queue.bottom;i<queue.top;i++)
		//	printf("%d %d %d\n",mew.y,mew.x,mew.step);
		//prtout();
		mew = pop(&queue);
		temp.step = mew.step;

		temp.y = mew.y+1;
		temp.x = mew.x;
		if(map[temp.y][temp.x]==1)	return temp.step+1;
		if(map[temp.y][temp.x]==0)
		{
			map[temp.y][temp.x] = -9;
			push(temp,&queue);
			queue.q[queue.top-1].step++;
		}
		temp.y = mew.y;
		temp.x = mew.x+1;

		if(map[temp.y][temp.x]==1)	return temp.step+1;
		if(map[temp.y][temp.x]==0)
		{
			map[temp.y][temp.x] = -9;
			push(temp,&queue);
			queue.q[queue.top-1].step++;
		}
		temp.y = mew.y-1;
		temp.x = mew.x;

		if(map[temp.y][temp.x]==1)	return temp.step+1;
		if(map[temp.y][temp.x]==0)
		{
			map[temp.y][temp.x] = -9;
			push(temp,&queue);
			queue.q[queue.top-1].step++;
		}
		temp.y = mew.y;
		temp.x = mew.x-1;

		if(map[temp.y][temp.x]==1)	return temp.step+1;
		if(map[temp.y][temp.x]==0)
		{
			map[temp.y][temp.x] = -9;
			push(temp,&queue);
			queue.q[queue.top-1].step++;
		}
	}//Queue is not empty;
	return 0;
}

void clrarr(void)
{
	int i, j;
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
			map[i][j] = -1;
	}
}

void prtout(void)
{
	int i, j;
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=10;j++)
		{
			printf("%2d ",map[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int term;
	int i, j;
	int step;
	CO mew;
	char temp[102];
	while(1)
	{
		queue.top = queue.bottom = 0;
		clrarr();
		gets(temp);
		term = atoi(temp);
		if(term==0)	break;
		for(i=0;i<term;i++)
		{
			gets(temp);
			for(j=0;j<strlen(temp);j++)
			{
				switch(temp[j])
				{
					case '#':
						map[i+1][j+1] = -1;
						break;
					case '.':
						map[i+1][j+1] = 0;
						break;
					case 'K':
						map[i+1][j+1] = -9;
						mew.y = i+1;
						mew.x = j+1;
						//printf("%d %d\n",mew.y,mew.x);
						mew.step = 0;
						break;
					case '@':
						map[i+1][j+1] = 1;
						break;
				}
			}
		}
		//prtout();

		step = bfs(mew);
		if(step) printf("%d\n",step);
		else	printf("= =\"\n");
	}
	return 0;
}
