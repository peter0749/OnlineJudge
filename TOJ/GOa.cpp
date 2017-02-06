#include <iostream>
#include <iomanip>
#include <string>
#define TERM 9
#define MAX 101
#define D 4

using namespace std;

typedef struct
{
    int x,y;
} ALPHA;

const int dire[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};
int cord[TERM][TERM] = {{0}};

int main(void)
{
    int i, j;
    int x, y;
    int breath = 0;
    ALPHA stk[MAX];
    int stk_top = -1;
    while(1)
    {
        stk_top = -1;
        for(i=0; i<TERM; i++)for(j=0; j<TERM; j++)
        {
            if(!(cin>>cord[i][j]))  return 0;
            if(cord[i][j]==1)
            {
                stk[++stk_top].x = j;
                stk[stk_top].y = i;
            }
        }
        breath = 0;
        while(stk_top!=-1)/*Stack not empty*/
        {
            for(i=0; i<D; i++)
            {
                x = stk[stk_top].x + dire[i][0];
                y = stk[stk_top].y + dire[i][1];
                if(x>=0&&y>=0&&x<TERM&&y<TERM&&cord[y][x]==0)
                {
                    breath++;
                    cord[y][x] = 2;
                }
            }
            stk_top--;
        }

        cout<<breath<<'\n';
    }
    return 0;
}
