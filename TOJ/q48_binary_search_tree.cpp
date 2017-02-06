#include <iostream>
#include <iomanip>
#include <string>
#define MAX 3000

using namespace std;

typedef struct node
{
    int key;
    struct node *lc;
    struct node *rc;
}btree;

void push(btree *ptr, const int key)
{
    if(key > ptr->key)/*key > rootkey, move to right subtree.*/
    {
        if(ptr->rc!=NULL)
            push(ptr->rc, key);
        else
        {
            ptr->rc = new btree;
            ptr->rc->lc = ptr->rc->rc = NULL;
            ptr->rc->key = key;
        }
    }
    else
    {
        if(ptr->lc!=NULL)
            push(ptr->lc, key);
        else
        {
            ptr->lc = new btree;
            ptr->lc->lc = ptr->lc->rc = NULL;
            ptr->lc->key = key;
        }
    }
}

void travel(btree *ptr)
{
    if(ptr==NULL)   return;
    travel(ptr->lc);
    //cout<<ptr->key<<'\n';
    travel(ptr->rc);
    cout<<ptr->key<<'\n';
    delete ptr;
}

int main(void)
{
    int keyin;
    btree *rootp = NULL;
    while(cin>>keyin)
    {
        if(rootp==NULL)
        {
            rootp = new btree;
            rootp->lc = rootp->rc = NULL;
            rootp->key = keyin;
        }
        else
            push(rootp,keyin);
        //travel(rootp);
    }
    travel(rootp);
    return 0;
}
