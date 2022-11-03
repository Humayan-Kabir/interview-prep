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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
            1. min heap
            2. push front of each list
            3. will take minimum among them, remove min one -> insert next elemenet
        */
        auto comparator = [&](ListNode *first, ListNode* second) -> bool {
            return first->val > second->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comparator)> pq(comparator);
        ListNode *sortedList = new ListNode();
        ListNode *current = sortedList;
        for(int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push(lists[i]);                
            }
        }
        while(!pq.empty()) {
            current->next = pq.top();
            pq.pop();
            current = current->next;
            if (current->next) {
                pq.push(current->next);
            }
        }
        return sortedList->next;      
    }
};