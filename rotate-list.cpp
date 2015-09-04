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
//     void rev(ListNode *start, ListNode *end) {
//         int temp;
//         ListNode *p;
//         while (start != end && end->next != start) {
//             temp = start->val;
//             start->val = end->val;
//             end->val = temp;
//             p = start;
//             start = start->next;
//             while (p->next != end) {
//                 p = p->next;
//             }
//             end = p;
//         }
//     }

//     ListNode* rotateRight(ListNode* head, int k) {

//         if (head == NULL) return head;
//         int len = 1;
//         ListNode *tail = head;
//         while (tail->next != NULL) {
//             tail = tail->next;
//             len++;
//         }
//         k = k % len;
//         if (k == 0) return head;
//         ListNode *k_node = head;
//         while (k > 1) {
//             k_node = k_node->next;
//             k--;
//         }

//         ListNode *start = head;
//         ListNode *end = tail;
//         rev(start, end);

//         start = head;
//         end = k_node;
//         rev(start, end);

//         start = k_node->next;
//         end = tail;
//         rev(start, end);

//         return head;
//     }
// };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || k == 0) return head;

        ListNode *tail = head;
        int len = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        k = k % len;
        tail->next = head;
        for (int i = 0; i < len - k; i++) {
            tail = tail->next;
        }
        head = tail->next;
        tail->next = NULL;

        return head;
        
    }
};