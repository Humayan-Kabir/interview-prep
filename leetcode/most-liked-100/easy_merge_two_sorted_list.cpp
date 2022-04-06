
#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	    if (l1 == nullptr) return l2;
	    if (l2 == nullptr) return l1;
	    ListNode *head = nullptr;
	    ListNode *tail = nullptr;
	    while(l1 && l2) {
	    	if (l1->val <= l2->val) {
			if (head == nullptr) {
				head = l1;
				tail = l1;
			} else {
				tail->next = l1;
				tail = tail->next;
			}
			l1 = l1->next;
		} else {
			if (head == nullptr) {
				head = l2;
				tail = l2;
			} else {
				tail->next = l2;
				tail = tail->next;
			}
			l2 = l2->next;
		}
        }
        
	    while(l1) {
	    	tail->next = l1;
		    l1 = l1->next;
            tail = tail->next;
	    }
	    while(l2) {
	    	tail->next = l2;
		    l2 = l2->next;
            tail = tail->next;
	    }
	    return head;
    }
};

