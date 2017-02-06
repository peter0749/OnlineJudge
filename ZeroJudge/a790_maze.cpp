#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#if 0
#include <conio.h>
#include <windows.h>
#define DEBUG
#endif
#define LEN 103

using namespace std;

char mu[LEN][LEN];

typedef struct
{
    short x,y;
    int step;
} CORD;

inline void prtout(int l, int w)
{
    for(int i=1; i<=l; i++)
    {
        for(int j=1; j<=w; j++)
            cout<<mu[i][j];
        cout<<"\n";
    }
}

inline void push(CORD *que, int &x, int &y, int &top, int step)
{
    if(mu[y][x]!='.' && mu[y][x]!='#')
    {
        que[++top].x = x;
        que[top].y = y;
        que[top].step = step+1;
    }
}

int pushoff(int len, CORD *que, int top, int fcount)
{
    int bottom=-1;
    int x, y;
    int step=1;
    while(bottom!=top && step<len)
    {
        ++bottom;//POP
        step = que[bottom].step;
        if(mu[que[bottom].y][que[bottom].x]=='F') fcount--;
        mu[que[bottom].y][que[bottom].x] = '.';
#ifdef DEBUG
        system("cls");
        prtout(9,60);
        cout<<"step: "<<step<<" firecount: "<<fcount<<endl;
        getch();
#endif

        x = que[bottom].x+1;
        y = que[bottom].y;
        push(que,x,y,top,step);

        x = que[bottom].x;
        y = que[bottom].y+1;
        push(que,x,y,top,step);

        x = que[bottom].x-1;
        y = que[bottom].y;
        push(que,x,y,top,step);

        x = que[bottom].x;
        y = que[bottom].y-1;
        push(que,x,y,top,step);
    }
    return fcount;
}

int main(void)
{
    CORD *que;
    int i, j;
    int w, l, tube;
    int firecount;
    int top;
    char temp[105];
    //freopen("testout.txt","w",stdout);
    for(i=0;i<LEN;i++)for(j=0;j<LEN;j++)mu[i][j]='#';
    que = new CORD[20000];
    if(que==NULL)   return -1;
    while((cin.getline(temp,105))!=NULL)
    {
        top = -1;
        firecount = 0;
        sscanf(temp,"%d%d%d",&w,&l,&tube);
        //cout<<temp<<endl;
        for(i=0; i<l; i++)
        {
            cin.getline(temp,105);
            //gets(temp);
            for(j=0; j<w; j++)
            {
                if(temp[j]=='S')
                {
                    que[++top].x = j+1;
                    que[top].y = i+1;
                    que[top].step = 1;
                }
                else if(temp[j]=='F')   firecount++;
                mu[i+1][j+1] = temp[j];
            }
        }
        //prtout(l,w);
        firecount = pushoff(tube,que,top,firecount);
        prtout(l,w);
        if(firecount==0)    cout<<"All Fires Extinguished!\n";
    }


    delete [] que;
    return 0;
}
