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
        unordered_map<ListNode*, bool> hashMap;
        while(head) {
            if (hashMap.find(head) != hashMap.end()) {
                return head;
            }
            hashMap[head] = true;
            head = head->next;
        } 
        return nullptr;
    }
};
