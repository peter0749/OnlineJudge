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
struct cmp {
    bool operator()(const ListNode *a, const ListNode *b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        ListNode *ptr = NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for (auto v : lists) {
            if (v!=NULL)
                heap.push(v);
        }
        while (!heap.empty()) {
            auto top = heap.top();
            heap.pop();
            if (head == NULL) {
                head = top;
                ptr = top;
            } else {
                ptr->next = top;
                ptr = ptr->next;
            }
            if (top->next != NULL)
                heap.push(top->next);
        }
        return head;
    }
};
