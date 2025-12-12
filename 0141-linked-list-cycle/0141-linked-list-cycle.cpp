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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;            // empty list -> no cycle

        ListNode* slow = head;
        ListNode* fast = head;

        // advance fast two steps and slow one step
        // stop if fast reaches end (no cycle) or if slow == fast (cycle)
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;        // they met -> cycle exists
        }

        return false;                              // fast hit NULL -> no cycle
    }
};
