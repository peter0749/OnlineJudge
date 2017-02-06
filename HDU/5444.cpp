#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
using namespace std;

typedef struct node {
    int val;
    struct node *l, *r;
}BT;
char stk[1010];
size_t top=0;

BT *init(BT *str, int val) {
    str = (BT*)malloc(sizeof(BT));
    str->val = val;
    str->l = str->r = NULL;
    return str;
}

BT *insert(BT *root, int val) {
    if(root==NULL) return init(root, val);
    if(val < root->val) root->l=insert(root->l, val);
    else root->r=insert(root->r, val);
    return root;
}

bool search(BT *root, int val) {
    if(root==NULL) return false;
    if(root->val==val) return true;
    if(val < root->val) {
        stk[top++] = 'E';
        return search(root->l, val);
    }
    stk[top++] = 'W';
    return search(root->r, val);
}

void des(BT *root) {
    if(root==NULL) return;
    des(root->r);
    des(root->l);
    free(root);
}

int main(void) {
    int T, N, Q;
    BT *root=NULL;
    scanf("%d", &T);
    int temp;
    while(T--) {
        scanf("%d",&N);
        for(int i=0; i<N; ++i) {
            scanf("%d", &temp);
            root = insert(root, temp);
        }
        scanf("%d", &Q);
        for(int i=0; i<Q; ++i) {
            scanf("%d", &temp);
            top=0;
            if(!search(root, temp)) puts("");
            else {
                stk[top] = '\0';
                puts(stk);
            }
        }
        des(root);
        root = NULL;
    }
    return 0;
}
