/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> st;

        // Step 1: Find middle (slow ends at midpoint)
        while (fast != NULL && fast->next != NULL) {
            st.push(slow->val);   // store first half in stack
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: If list has odd length, skip the middle node
        if (fast != NULL) {  
            slow = slow->next;
        }

        // Step 3: Compare second half with stack (first half in reverse)
        while (slow != NULL) {
            if (st.top() != slow->val) return false;
            st.pop();
            slow = slow->next;
        }

        return true;
    }
};
