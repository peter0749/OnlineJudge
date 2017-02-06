#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#define MAX 100003

using namespace std;

typedef struct node
{
    int x, y;
}CORD;

CORD data[MAX];

int cmpx (const void *a, const void *b)
{
    CORD *c, *d;
    c = (CORD*)a;
    d = (CORD*)b;
    if(c->x!=d->x)  return c->x - d->x;
    else    return c->y - d->y;
}

int main(void)
{
    int term;
    while(cin >> term)
    {
        for(int i=0; i<term; i++) cin>>data[i].x>>data[i].y;
        qsort(data, term, sizeof(CORD), cmpx);
        cout<<data[0].x<<" "<<data[0].y<<'\n';
        for(int i=1; i<term; i++)
        {
            cout<<data[i].x<<" "<<data[i].y<<'\n';
        }
    }

    return 0;
}
