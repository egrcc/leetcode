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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p = l2;
        ListNode *current = l1;
        ListNode *prior = l1;
        ListNode *temp;
        while (p != NULL) {
            if (current == l1) {
                if (current == NULL) return l2;
                if (current->val > p->val) {
                    temp = p->next;
                    p->next = current;
                    prior = p;
                    l1 = p;
                    p = temp;
                } else {
                    prior = current;
                    current = current->next;
                }
            } else {
                while (current != NULL) {
                    if (current->val > p->val) {
                        temp = p->next;
                        p->next = current;
                        prior->next = p;
                        prior = p;
                        p = temp;
                        break;
                    } else {
                        prior = current;
                        current = current->next;
                    }
                }
                if (current == NULL) {
                    prior->next = p;
                    break;
                }
            } 
        }
        return l1;         
    }
};