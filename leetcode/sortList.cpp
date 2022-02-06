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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        List *mid = splitAtMid(head);
        List *left = sortList(head);
        List *right = sortList(mid);
        return merge(left, right);
    }
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode *temp = new ListNode();
        while(left && right) {
            if (left->val < right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
        }
        if (left) temp->next = left;
        if (right) temp->next = right;
        return temp->next;
    }
    ListNode *splitAtMid(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *midPrev = nullptr;
        while(fast && fast->next) {
            midPrev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        midPrev->next = nullptr;
        return slow;
    }
};


