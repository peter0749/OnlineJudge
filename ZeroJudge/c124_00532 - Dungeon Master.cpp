#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 40

using namespace std;

typedef struct node
{
    char x;
    char y;
    char z;
    unsigned short step;
    struct node *next;
}CORD;
CORD *head = NULL, *tail = NULL;
char book[MAX][MAX][MAX] = {{{0}}};

const char dire[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

inline void prtout(int z, int y, int x)
{
    int i, j, k;
    for(i=1;i<=z;i++)
    {
        for(j=1;j<=y;j++)
        {
            for(k=1;k<=x;k++)
            {
                cout<<book[i][j][k];
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

inline int push(int z, int y, int x, int step)
{
    CORD *ptr;
    if(book[z][y][x]=='#')  return 0;
    if(book[z][y][x]=='E')  return step;
    book[z][y][x] = '#';
    //ptr = new CORD;
    //ptr = (CORD*)malloc(sizeof(CORD));
    ptr = new CORD;
    ptr->x = x;
    ptr->y = y;
    ptr->z = z;
    ptr->step = step;
    ptr->next = NULL;
    tail->next = ptr;
    tail = ptr;
    return 0;
}

inline CORD *pop(void)
{
    CORD *ptr;
    CORD *tobeadd;
    if(head->next==NULL)
    {
        return NULL;
    }
    //tobeadd = (CORD*)malloc(sizeof(CORD));
    tobeadd = new CORD;
    *(tobeadd) = *(head->next);
    tobeadd->next = NULL;
    ptr = head;
    head = head->next;
    ptr->next = NULL;
    //free(ptr);
    delete ptr;
    return tobeadd;
}

inline int bfs(int sz, int sy, int sx)
{
    int i;
    int solution = 0;
    CORD *test=NULL;
    if(solution = push(sz,sy,sx,0)) return solution;
    while(1)
    {
        test = pop();
        //cout<<test.x<<endl;
        if(test==NULL)break;    /*queue empty!*/

        //cout<<test.step<<endl;
        //book[test->z][test->y][test->x] = '#';
        for(i=0;i<6;i++)
        {
            if(solution = (push(test->z+dire[i][0],test->y+dire[i][1],test->x+dire[i][2],test->step+1)))
            {
                delete test;
                test = NULL;
                return solution;
            }
        }
        //free(test);
        delete test;
        test=NULL;
    }
    return 0;
}

void dstry(CORD *ptr)
{
    if(ptr->next!=NULL) dstry(ptr->next);
    delete ptr;
    //free(ptr);
}

int main(void)
{
    int z, y, x;
    int i, j, k;
    int inx, iny, inz;
    int step;
    char temp[MAX];
    for(i=0;i<MAX;i++)for(j=0;j<MAX;j++)for(k=0;k<MAX;k++)book[i][j][k] = '#';
    while(scanf("%d%d%d",&z,&y,&x)==3)
    {
        if(z==0&&x==0&&y==0)    return 0;
        head = new CORD;
        head->next = NULL;
        //head->x = head->y = head->z = 0;
        tail = head;
        for(i=0;i<z;i++)
        {
            for(j=0;j<y;j++)
            {
                scanf("%s",temp);
                for(k=0;k<x;k++)
                {
                    book[i+1][j+1][k+1] = temp[k];
                    if(temp[k]=='S')
                    {
                        inz = i+1;
                        iny = j+1;
                        inx = k+1;
                    }
                }
            }
        }
        //prtout(z,y,x);
        step = bfs(inz,iny,inx);
        if(step) cout<<"Escaped in "<<step<<" minute(s).\n";
        else     cout<<"Trapped!\n";
        //prtout(z,y,x);
        tail = NULL;
        dstry(head);
        //delete head;
        head = NULL;
    }
    return 0;
}
