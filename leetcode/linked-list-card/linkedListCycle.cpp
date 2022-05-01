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
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast) {
        	slow = slow->next;
        	fast = fast->next ? fast->next->next : nullptr;
        	if (slow == fast) return true;
        }
        return false;
    }
};
