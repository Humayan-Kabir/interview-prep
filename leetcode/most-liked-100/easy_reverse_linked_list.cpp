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
    ListNode *revRoot = nullptr;
    void findRev(ListNode *root) {
        if(root == nullptr || root->next == nullptr) {
            revRoot = root;
            return;
        }
        findRev(root->next);
        root->next->next = root;
        root->next = nullptr;
    }
    ListNode* reverseList(ListNode* head) {
        findRev(head);
        return revRoot;
    }
};
