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
//     bool isPalindrome(ListNode* head) {
//         if (head == NULL || head->next == NULL) return true;
//         ListNode *tail = head;
//         while (tail->next != NULL) {
//             tail = tail->next;
//         }
//         if (head->val == tail->val) {
//             if (head == tail || head->next == tail) return true;
//             head = head->next;
//             ListNode *temp = head;
//             while (temp->next != tail) temp = temp->next;
//             temp->next = NULL;
//             return isPalindrome(head);
//         } else {
//             return false;
//         }
//     }
// };

// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         if (head == NULL || head->next == NULL) return true;
//         ListNode *tail = head;
//         while (tail->next != NULL) {
//             tail = tail->next;
//         }
//         while (true) {
//             if (head->val != tail->val) {
//                 return false;
//             } else {
//                 if (head == tail || head->next == tail) return true;
//                 head = head->next;
//                 ListNode *temp = head;
//                 while (temp->next != tail) temp = temp->next;
//                 temp->next = NULL;
//                 tail = temp;
//             }

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

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = slow->next;
        head2 = reverseList(head2);
        while (head2) {
            if (head2->val != head->val) {
                return false;
            } else {
                head2 = head2->next;
                head = head->next;
            }
        }
        return true;
    }
};