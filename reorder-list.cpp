/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         if (head && head->next && head->next->next) {
//             ListNode *tail = head;
//             ListNode *prev;
//             while (tail->next) {
//                 prev = tail;
//                 tail = tail->next;
//             }
//             prev->next = NULL;
//             ListNode *temp = head->next;
//             reorderList(temp);
//             head->next = tail;
//             tail->next = temp;
//         }
//     }
// };

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *prior = NULL;
        ListNode *current = head;
        ListNode *next;
        
        next = current->next;
        current->next = prior;
        head = reverseList(next);
        next->next = current;
        return head;
    }

    void reorderList(ListNode* head) {
        if (head && head->next && head->next->next) {
            ListNode *slow = head, *fast = head;
            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode *q = reverseList(slow->next);
            slow->next = NULL;
            ListNode *p = head;
            while (q) {
                ListNode *temp1 = p->next;
                ListNode *temp2 = q->next;
                q->next = p->next;
                p->next = q;
                p = temp1;
                q = temp2;
            }
        }
    }
};