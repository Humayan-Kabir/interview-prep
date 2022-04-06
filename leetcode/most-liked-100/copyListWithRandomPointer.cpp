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
        if (head == nullptr) {
            return nullptr;
        }
        unordered_map<Node*, int> mainListMap;
        unordered_map<int, Node*> copiedListMap;
        Node *copy = new Node(head->val);
        Node *temp = copy;
        Node *tempHead = head;
        int curPosition = 0;
        while(head) {
            mainListMap[head] = curPosition;
            copiedListMap[curPosition] = temp;
            curPosition++;
            head = head->next;
            if (head) {
                temp->next = new Node(head->val);    
            } else {
                temp->next = nullptr;
            }
            
            temp = temp->next;
        }
        temp = copy;
        while(tempHead) {
           if (tempHead->random == nullptr) {
                temp->random = nullptr;
                tempHead = tempHead->next;
                temp = temp->next;
                continue;
           } 
           int pos = mainListMap[tempHead->random];
           temp->random = copiedListMap[pos];
           temp = temp->next;
           tempHead = tempHead->next;
        }
        return copy;
    }
};
