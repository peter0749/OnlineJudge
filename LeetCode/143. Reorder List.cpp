/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> queue;
        ListNode* ptr = head;
        while(ptr!=NULL) {
            queue.push_back(ptr);
            ptr = ptr->next;
        }
        ptr = head;
        for (int l=0, r=queue.size()-1; l<=r; ++l, --r) {
            ptr->next = queue[l];
            queue[l]->next = queue[r];
            ptr = queue[r];
        }
        ptr->next = NULL;
    }
};
