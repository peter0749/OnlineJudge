/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *r, *l;
    struct ListNode head;
    head.next=NULL;
    r = l = &head;
    while(l1&&l2) {
        if(l1->val<l2->val) {
            l->next = l1;
            l1 = l1->next;
        } else {
            l->next = l2;
            l2 = l2->next;
        }
        l = l->next;
    }
    while(l1) { l->next=l1; l=l->next; l1=l1->next; }
    while(l2) { l->next=l2; l=l->next; l2=l2->next; }
    
    l=r;
    r=r->next;
    l->next=NULL;
    return r;
}
