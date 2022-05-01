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
    ListNode *detectCycle(ListNode *head) {
        ListNode *intersection = getIntersect(head);
        if (intersection == nullptr) return nullptr;
        ListNode *ptr1 = intersection->next;
        ListNode *ptr2 = head;
        while(ptr1 != ptr2) {
        	ptr1 = ptr1->next;
        	ptr2 = ptr2->next;
        }
        return ptr1;
    }
    ListNode *getIntersect(ListNode *head) {
    	if (head == nullptr) return head;
    	ListNode *slow = head;
    	ListNode *fast = head->next;
    	while(fast) {
    		slow = slow->next;
    		fast = fast->next ? fast->next->next : nullptr;
    		if(slow == fast) return slow;
    	}
    	return nullptr;
    }
};
