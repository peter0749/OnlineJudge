#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 99

void ch_dir(int*);

int bitmap[105][105] = {{0}};

int main(void)
{
	int pofix;
	int dir, bk_dir;
	int k, i, j;
	int term;
	int n;
	scanf("%d",&term);	/*Number of terms*/
	i = j = (MAX-1)/2;	/*Position at first*/
	k = 1;
	dir = bk_dir = 1;	/*Default direction (1 for R, 2 for D, 3 for L, 4 for U)*/
	while(k<=MAX*MAX)
	{
		switch(dir)
		{
			case 1:
				if(bitmap[i][j+1] != 0)
				{
					dir = bk_dir;
				}
				else
				{
					bitmap[i][j++] = k++;
					bk_dir = dir;
					ch_dir(&dir);
				}
				break;
			case 2:
				if(bitmap[i+1][j] != 0)
				{
					dir = bk_dir;
				}
				else
				{
					bitmap[i++][j] = k++;
					bk_dir = dir;
					ch_dir(&dir);
				}
				break;
			case 3:
				if(bitmap[i][j-1] != 0)
				{
					dir = bk_dir;
				}
				else
				{
					bitmap[i][j--] = k++;
					bk_dir = dir;
					ch_dir(&dir);
				}
				break;
			case 4:
				if(bitmap[i-1][j] != 0)
				{
					dir = bk_dir;
				}
				else
				{
					bitmap[i--][j] = k++;
					bk_dir = dir;
					ch_dir(&dir);
				}
				break;
		}

	}
#if 0
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
			printf("%4d",bitmap[i][j]);
		printf("\n");
	}
#endif

	while(term--)
	{
		scanf("%d",&n);
		pofix = (99-n)/2;
		n += pofix;
		for(i=pofix;i<n;i++)
		{
			for(j=pofix;j<n;j++)
			{
				if(j>pofix)
					printf(" ");
				printf("%4d",bitmap[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}

void ch_dir(int *dir)
{
	/*Counterclockwise*/
	switch(*dir)
	{
		case 1:
			*dir = 4;
			break;
		case 2:
			*dir = 1;
			break;
		case 3:
			*dir = 2;
			break;
		case 4:
			*dir = 3;
			break;
	}
}
