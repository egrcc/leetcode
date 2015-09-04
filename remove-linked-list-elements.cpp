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
    ListNode* removeElements(ListNode* head, int val) {
        
        
        while ((head != NULL) && (head->val == val)) {
            head = head->next;
        }
        
        if (head == NULL) return head;

        ListNode *p = head;
        ListNode *v = head->next;

        while (v != NULL) {
            if (v->val == val) {
                p->next = v->next;
                v = v->next;
            } else {
                p = v;
                v = v->next;
            }

        }

        return head;
    }
};