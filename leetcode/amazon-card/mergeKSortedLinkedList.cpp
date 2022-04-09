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
    	auto comp = [](ListNode* left, ListNode* right) -> bool {
    		return left->val > right->val;	
    	};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for(int i = 0; i < lists.size(); i++) {
        	if (lists[i]) {
        		pq.push(lists[i]);
        	}
        }
        ListNode *dummyHead = new ListNode();
        ListNode *ans = dummyHead;
        while(!pq.empty()) {
        	ListNode* top = pq.top();
        	pq.pop();
        	dummyHead->next = top;
            dummyHead = dummyHead->next;
        	if (top->next) {
        		pq.push(top->next);
        	}
        }
        return ans->next;
    }
};
