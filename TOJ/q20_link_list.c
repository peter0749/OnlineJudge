#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#define MAX 1005

typedef struct LS
{
    struct LS *previous;
    struct LS *next;
    short gid;
    char inq;
    int m;
} dlinklist;

short groups[1000000] = {0};
dlinklist *inspoi[1001];

dlinklist *pop(dlinklist *bottom)
{
    dlinklist *ptr;
    if(bottom->next==NULL)  return bottom;
    ptr = bottom->next;
    ptr->inq = 0;
    return ptr;
}

dlinklist *push(int id, int gid, dlinklist *queuetail)
{
    dlinklist *data;
    data = (dlinklist*)malloc(sizeof(dlinklist));
    data->gid = gid;
    data->m = id;
    data->previous = queuetail;
    queuetail->next = data;
    data->next = NULL;
    return data;//new tail
}

dlinklist *insert(int id, int gid, dlinklist *bottom, dlinklist *queuetail)
{
    dlinklist *position;
    dlinklist *tobeadd;
    if(bottom->next == NULL || queuetail->gid == gid)
    {
        tobeadd = push(id,gid,queuetail);
        tobeadd->inq = 1;
        inspoi[gid] = tobeadd;
        return tobeadd;
    }

    if(inspoi[gid]!=NULL && inspoi[gid]->inq==1)
    {
        tobeadd = (dlinklist*)malloc(sizeof(dlinklist));
        tobeadd->m = id;
        tobeadd->gid = gid;
        position = inspoi[gid];
        tobeadd->previous = position;
        tobeadd->next = position->next;
        tobeadd->next->previous = tobeadd;
        position->next = tobeadd;
        tobeadd->inq = 1;
        inspoi[gid] = tobeadd;
        return queuetail;
    }
    tobeadd = push(id,gid,queuetail);
    tobeadd->inq = 1;
    inspoi[gid] = tobeadd;
    return tobeadd;
}

void prtout(dlinklist *head, dlinklist *bottom)
{
    dlinklist *ptr = head->next;
    while(ptr!=NULL && bottom->next!=ptr)
    {
        printf("%d\n",ptr->m);
        ptr = ptr->next;
    }
}

int main(void)
{
    int term = 1;
    char op[10];
    dlinklist *head = NULL, *tail = NULL, *bottom = NULL;
    int gcount;
    int n, i, j;
    int id;
    while(scanf("%d",&gcount)!=EOF)
    {
        for(i=0; i<1001; i++) inspoi[i] = NULL;
        memset(groups,0,sizeof(groups));
        if(head==NULL)
        {
            head = (dlinklist*)malloc(sizeof(dlinklist));
            head->gid = head->m = -1;
            head->next = head->previous = NULL;
            tail = bottom = head;
        }
        for(i=1; i<=gcount; i++)
        {
            scanf("%d",&n);
            for(j=0; j<n; j++)
            {
                scanf("%d",&id);
                groups[id] = i;
            }
        }
        /*End of input*/

        while(1)/*Operations*/
        {
            scanf("%s",op);
            if(*op=='S') break;
            else if(*op=='E')
            {
                scanf("%d",&id);
                if(groups[id]>0)/*Is chinese*/
                {
                    tail = insert(id,groups[id],bottom,tail);
                }
                else
                {
                    tail = push(id,groups[id],tail);
                }
            }
            else if(*op=='D')
            {
                bottom = pop(bottom);
            }
        }
        printf("Line #%d\n", term);
        prtout(head,bottom);
        free(head);
        head = tail = bottom = NULL;
        term++;
    }
    return 0;
}
