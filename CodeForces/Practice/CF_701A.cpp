#include <bits/stdc++.h>
#define MAX 200

using namespace std;
typedef struct
{
    int index;
    int number;
}CARD;

int cmp(const void *a, const void *b)
{
    CARD *c = (CARD*)a;
    CARD *d = (CARD*)b;
    return c->number - d->number;
}

CARD testcard[MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    int n;
    int sum;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>testcard[i].number;
            testcard[i].index = i+1;
        }
        qsort(testcard, n, sizeof(CARD), cmp);
        //r(int i=0; i<n; i++) cout<<testcard[i].number<<' '<<testcard[i].index<<endl;
        int i=0, j=n-1;
        while(i<j)
        {
            cout<<testcard[i].index<<' '<<testcard[j].index<<'\n';
            i++;j--;
        }
    }
    return 0;
}
