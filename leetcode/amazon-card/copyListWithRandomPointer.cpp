/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    	/*
    	 1->2->3
    	 1->1'->2->2'->3->3'
    	*/
        if (!head) {
        	return head;
        }
        //make double the size of the list 
        Node *ptr = head;
        while(ptr) {
        	ListNode *newNode = new ListNode(ptr->val);
        	nodeNode->next = ptr->next;
        	ptr->next = newNode;
        	ptr = newNode->next;
        }
        //assign random
        ptr = head;
        while(ptr) {
        	ptr->next->random = (ptr->random ? ptr->random->next: nullptr);
        	ptr = ptr->next->next;
        }
        //extract original and duplicate list
        Node *oldListHead = head;
        Node *newListHead = head->next;
        Node *ansHead = newListHead;
       	while(oldListHead) {
       		oldListHead->next = oldListHead->next->next;
       		newListHead->next = newListHead->next ? newListHead->next->next : nullptr;
       		oldListHead = oldListHead->next;
       		newListHead = newListHead->next;
       	}
       	return ansHead;
    }
};
