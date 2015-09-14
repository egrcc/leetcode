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
//     ListNode* reverseList(ListNode* head) {
//         if (head == NULL || head->next == NULL) return head;
//         ListNode *tail = head;
//         while (tail->next != NULL) {
//             tail = tail->next;
//         }
//         rev(head, tail);
//         return head;
//     }
//     void rev(ListNode *head, ListNode *tail) {
//         if (head == tail || tail->next == head) return;
//         int temp = tail->val;
//         tail->val = head->val;
//         head->val = temp;
//         // head = head->next;
//         ListNode *prior = head;
//         while (prior->next != tail) prior = prior->next;
//         rev(head->next, prior);
//     }
// };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (head == NULL || head->next == NULL) return head;
//         ListNode *tail = head;
//         while (tail->next != NULL) {
//             tail = tail->next;
//         }
//         ListNode *first = head;
//         while (first != tail && tail->next != first) {
//             int temp = tail->val;
//             tail->val = first->val;
//             first->val = temp;
//             ListNode *prior = first;
//             first = first->next;
//             while (prior->next != tail) prior = prior->next;
//             tail = prior;
//         }
//         return head;
//     }
// };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (head == NULL || head->next == NULL) return head;
//         ListNode *prior = NULL;
//         ListNode *current = head;
//         ListNode *next;
//         while (current != NULL) {
//             next = current->next;
//             current->next = prior;
//             prior = current;
//             current = next;
//         }
//         head = prior;
//         return head;
//     }
// };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (head == NULL || head->next == NULL) return head;
//         ListNode *prior = NULL;
//         ListNode *current = head;
//         ListNode *next;
        
//         next = current->next;
//         current->next = prior;
//         head = reverseList(next);
//         next->next = current;
//         return head;
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
        ListNode *new_head = reverseList(next);
        next->next = current;
        return new_head;
    }
};