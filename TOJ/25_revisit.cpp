#include <iostream>
#include <iomanip>
#include <string>
#define MAX 102

using namespace std;

typedef struct node
{
    int uid;
    struct node *next;
} linkedlist;


linkedlist *heads[MAX] = {NULL};
linkedlist *tails[MAX] = {NULL};

void dstry(linkedlist *ptr)
{
    cout<<" "<<ptr->uid;
    if(ptr->next!=NULL) dstry(ptr->next);
    delete ptr;
}

void travel(linkedlist *ptr)
{
    if(ptr->next==NULL)
    {
        cout<<" empty";
        delete ptr;
        return;
    }
    dstry(ptr->next);
    delete ptr;
}

void push(int gid, int uid)
{
    linkedlist *ptr;
    ptr = new linkedlist;
    ptr->uid = uid;
    ptr->next = NULL;
    tails[gid]->next = ptr;
    tails[gid] = ptr;
}

void pop(int gid)
{
    linkedlist *ptr;
    if(heads[gid]->next==NULL)
    {
        cout<<"queue "<<gid<<" is empty!\n";
        return;
    }
    ptr = heads[gid];
    heads[gid] = heads[gid]->next;
    ptr->next = NULL;
    delete ptr;
    if(heads[gid]->next==NULL)  tails[gid] = heads[gid];
}

void join(int des, int src)
{
    if(heads[src]->next==NULL)  return;
    tails[des]->next = heads[src]->next;
    tails[des] = tails[src];
    heads[src]->next = NULL;
    tails[src]=heads[src];
}

int main(void)
{
    int n,m;
    int gid, uid;
    string str;
    while(cin>>n>>m)
    {
        for(int i=1; i<=n; i++)
        {
            heads[i] = new linkedlist;
            heads[i]->next = NULL;
            heads[i]->uid = -1;
            tails[i] = heads[i];
            //cout<<tails[i]->uid;
        }
        while(m--)
        {
            cin>>str;
            if(str=="ADD")
            {
                cin>>gid>>uid;
                push(gid,uid);
            }
            else if(str=="LEAVE")
            {
                cin>>gid;
                pop(gid);
            }
            else if(str=="JOIN")
            {
                cin>>gid>>uid;
                join(uid,gid);
            }
        }

        for(int i=1; i<=n; i++)
        {
            cout<<"queue "<<i<<":";
            travel(heads[i]);
            cout<<"\n";
            //dstry(heads[i]);
            //delete heads[i];
            heads[i] = NULL;
            tails[i] = NULL;
        }
    }
    return 0;
}
