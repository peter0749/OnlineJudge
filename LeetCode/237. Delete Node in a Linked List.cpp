/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        ListNode* curr = node;
        ListNode* next = node->next;
        
        while (next) {
            curr->val = next->val;
            prev = curr;
            curr = next;
            next = curr->next;
        }
        
        prev->next = NULL;
        
    }
};
