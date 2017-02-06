#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#define MAX 20
#define TSIZE 100

typedef unsigned short USI;

using namespace std;
USI book[MAX][MAX] = {{0}};

inline void prtout(int len)
{
    for(int i=1; i<=len; i++)
    {
        if(book[i][1]==2)
            cout<<'#';
        else
            cout<<book[i][1];
        for(int j=2; j<=len; j++)
        {
            if(book[i][j]==2)
                cout<<" #";
            else
                cout<<' '<<book[i][j];
        }
        cout<<"\n";
    }
}

bool dfs(const int len, int x, int y)
{
    //cout<<x<<" "<<y<<endl;
    if(y==len-1 && x==len-1)
    {
        book[y][x] = 2;
        return true;
    }
    if(book[y][x]!=0)  return false;
    book[y][x] = 2;
    if(dfs(len,x,y+1)+dfs(len,x+1,y)+dfs(len,x,y-1)+dfs(len,x-1,y))
    {
        //book[y][x] = 0;
        return true;
    }
    book[y][x] = 0;
    return false;
}

int main(void)
{
    int len = 0;
    int i, j;
    char input[TSIZE];
    for(i=0; i<MAX; i++)for(j=0; j<MAX; j++)book[i][j] = 1;
    cin.getline(input,TSIZE);
    j = 0;
    for(i=0; i<strlen(input); i++)
    {
        if(input[i]=='1')
            book[1][++j] = 1;
        else if(input[i]=='0')
            book[1][++j] = 0;
    }
    len = j;
    for(i=1; i<len; i++)
    {
        for(j=0; j<len; j++)
        {
            cin>>book[i+1][j+1];
        }
    }
    //prtout(len);
    dfs(len,2,2);
    prtout(len);

    return 0;
}

