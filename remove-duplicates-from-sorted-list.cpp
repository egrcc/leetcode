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
        int current = head->val;
        ListNode *prev = head;
        ListNode *p = head->next;
        while (p != NULL) {
            if (p->val != current) {
                current = p->val;
                prev = prev->next;
                p = p->next;
            } else {
                prev->next = p->next;
                p = p->next;
            }
        }
        return head;
        
    }
};