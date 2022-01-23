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
    ListNode* getIntersect(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return slow;
        }
        return nullptr;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *intersect = getIntersect(head);
        while(intersect != nullptr && head != intersect) {
            intersect = intersect->next;
            head = head->next;
        }
        return intersect;
    }
};
