#include <iostream>
#include <iomanip>
#include <string>
#define MAX 100000

using namespace std;

typedef struct coord
{
    int x,y;
    int step;
} CORD;

CORD que[MAX];
int mapp[105][105] = {{0}};

void prtmu(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<right<<"   "<<mapp[i][j];
        cout<<"\n";
    }
}

inline void pushque(int ¤t, int bottom, int x, int y)
{
    if(mapp[y][x]==0)
    {
        que[++current].x = x;
        que[current].y = y;
        que[current].step = que[bottom].step+1;
    }
}

int bfs(int n)
{
    int x, y;
    int top=0, bottom=-1;
    que[0].x=que[0].y=2;
    que[0].step=1;
    while(top!=bottom)
    {
        bottom++;/*POP*/
        mapp[que[bottom].y][que[bottom].x]=que[bottom].step;
        if(que[bottom].y==n-1 && que[bottom].x==n-1)    return que[bottom].step;
        x = que[bottom].x;
        y = que[bottom].y+1;
        pushque(top,bottom,x,y);

        x = que[bottom].x+1;
        y = que[bottom].y;
        pushque(top,bottom,x,y);

        x = que[bottom].x;
        y = que[bottom].y-1;
        pushque(top,bottom,x,y);

        x = que[bottom].x-1;
        y = que[bottom].y;
        pushque(top,bottom,x,y);
    }
    return 0;
}

int main(void)
{
    int term, step;
    int i, j;
    char temp[1000];
    for(i=0; i<105; i++)
        for(j=0; j<105; j++)
            mapp[i][j] = -1;
    while(cin>>term)
    {
        for(i=1; i<=term; i++)
        {
            cin>>temp;
            for(j=1; j<=term; j++)
            {
                if(temp[j-1]=='.')
                    mapp[i][j] = 0;
                else
                    mapp[i][j] = -1;
            }
        }
        //prtmu(term);
        step=bfs(term);
        //prtmu(term);
        if(step==0)
            cout<<"No solution!"<<"\n";
        else
            cout<<step<<"\n";
    }
    return 0;
}
