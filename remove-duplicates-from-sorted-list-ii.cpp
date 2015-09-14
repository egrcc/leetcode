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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        
        ListNode dummy(0);
        ListNode *prev = &dummy;
        prev->next = head;
        ListNode *p = head;
        int current = p->val;
        bool duplicate = false;

        while (p->next != NULL) {
            if (p->next->val == current) {
                duplicate = true;
                p = p->next;
            } else {
                if (duplicate) {
                    p = p->next;
                    prev->next = p;
                    current = p->val;
                    duplicate = false;
                } else {
                    prev = p;
                    p = p->next;
                    current = p->val;
                }
            }
        }
        if (duplicate) {
            prev->next = NULL;
        }

        return dummy.next;
        
    }
};