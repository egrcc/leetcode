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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *p = head;
        while (p != NULL && p->next != NULL) {
            prev->next = p->next;
            p->next = p->next->next;
            prev->next->next = p;
            prev = p;
            p = p->next;
        }
        return dummy->next;      
    }
};