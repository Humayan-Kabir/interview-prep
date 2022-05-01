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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        while(ptr1 != ptr2) {
        	ptr1 = ptr1 == nullptr ? headB : ptr1->next;
        	ptr2 = ptr2 == nullptr ? headA : ptr2->next;
        }
        return ptr1;
    }
};
