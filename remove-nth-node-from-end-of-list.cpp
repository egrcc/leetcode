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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy, *q = dummy;
        int step = 0;
        while (step < n) {
            p = p->next;
            step++;
        }
        while (p->next != NULL) {
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return dummy->next;        
    }
};