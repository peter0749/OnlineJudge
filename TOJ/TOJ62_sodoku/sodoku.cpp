#include <bits/stdc++.h>
#define MAX 83
#define SIZE 9
#define TSIZE 30
#define MASK 511

using namespace std;

typedef struct
{
    int key;
    int x;
    int y;
} UNDET;

UNDET dots[MAX];
int book[SIZE][SIZE];
unsigned int testbit[TSIZE];

void prtout(void)
{
    int i, j;
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            printf("%d",book[i][j]);
        }
        //printf("\n");
    }
    printf("\n");
}

int dfs(const int max_d, int depth)
{
    int i, j;
    int indexa = dots[depth].y;
    int indexb = SIZE+dots[depth].x;
    int indexc = 2*SIZE+(dots[depth].y/3)*3+(dots[depth].x/3);
    unsigned int tb=0, ta=0;

    if(max_d<depth)
    {
        for(i=0; i<=max_d; i++)book[dots[i].y][dots[i].x] = dots[i].key;
        prtout();
        return 1;
    }
    else
    {
        //testbit[2*SIZE+(i/3)*3+(j/3)] |= (1<<book[i][j]);
        tb = testbit[indexa] | testbit[indexb] | testbit[indexc];
        for(i=1; i<=SIZE; i++)
        {
            if(!(tb&(1<<i)))
            {
                /*Mark*/
                testbit[indexa] |= (1<<i);
                testbit[indexb] |= (1<<i);
                testbit[indexc] |= (1<<i);
                dots[depth].key = i;
                if(dfs(max_d,depth+1))  return 1;/*Track*/
                /*UNMark*/
                testbit[indexa] &= ~(1<<i);
                testbit[indexb] &= ~(1<<i);
                testbit[indexc] &= ~(1<<i);
            }
        }
    }
    return 0;
}

int main(void)
{
    //cin.sync_with_stdio(false);
    /*
    if(testbit[indexa] & testbit[indexb]!=0 ||\
            testbit[indexb] & testbit[indexc]!=0 ||\
            testbit[indexc] & testbit[indexa]!=0)
                return 0;
    */
    char temp[MAX];
    int undet_count;
    int i, j;
    int indexa, indexb, indexc;
    int fail=0;
    int index;
    while((cin.getline(temp,MAX))!=NULL)
    {
        if(strcmp(temp,"end")==0)break;
        undet_count = -1;
        fail = 0;
        for(i=0; i<TSIZE; i++) testbit[i]=0;
        for(i=0; i<SIZE; i++)
        {
            for(j=0; j<SIZE; j++)
            {
                index = i*SIZE+j;
                //book[i][j] = temp[index];
                if(temp[index]=='.')
                {
                    book[i][j] = -1;
                    ++undet_count;
                    dots[undet_count].x = j;
                    dots[undet_count].y = i;
                    dots[undet_count].key = -1;
                }
                else
                {
                    book[i][j] = temp[index]-'0';
                    indexa = i;
                    indexb = SIZE+j;
                    indexc = 2*SIZE+(i/3)*3+(j/3);
                    if(testbit[indexa]&(1<<book[i][j])||testbit[indexb]&(1<<book[i][j])||testbit[indexc] & (1<<book[i][j]))
                    {
                        fail = 1;
                        break;
                    }
                    else
                    {
                        testbit[indexa]|=(1<<book[i][j]);
                        testbit[indexb]|=(1<<book[i][j]);
                        testbit[indexc] |= (1<<book[i][j]);
                    }
                }
            }
        }
        if(fail||!dfs(undet_count,0))puts("No solution.");
    }
    return 0;
}
