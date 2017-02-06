#include <stdio.h>
#include <stdlib.h>

void loop(void);
void prtout(int RANK[], int len, int *first)
{
    int i;

    printf("%d",RANK[1]);
    for(i=2; i<=len; i++)
    {
        printf(" %d",RANK[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int main(void)
{
    //freopen("testout.txt","w",stdout);
    loop();
    return 0;
}

void loop(void)
{
    int n,m,i,j,k,len;
    int first = 1;
    int op,target;
    int ID[100005] = {0}, RANK[100005] = {0};

    while(scanf("%d",&n)!=EOF)
    {
        len = n;
        for(i=1; i<=n; i++)
        {
            ID[i] = RANK[i] = i;
        }

        scanf("%d",&m);
        for(i=1; i<=m; i++)
        {
            //prtout(RANK,len,&first);
            scanf("%d %d",&op,&target);
            if(op)//If 1
            {
                if(ID[target] > 1)
                {
                    j = ID[target]-1; //RANK to be swap, which RANK is lower(-1) than target
                    k = RANK[j];      //ID to be swap

                    swap(&RANK[ID[target]],&RANK[j]);       //Swap the IDs in RNAK[]
                    swap(&ID[target],&ID[k]);               //Swap the RANKs in ID[]
                }
            }
            else//If 0
            {
                len--;
                for(j=ID[target]; j<=n; j++)
                {
                    RANK[j] = RANK[j+1];
                    ID[RANK[j]]--;
                }
            }
        }
        prtout(RANK,len,&first);
    }

}
