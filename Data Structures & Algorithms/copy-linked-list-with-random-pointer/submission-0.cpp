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
        if(head == nullptr){
            return nullptr;
        }

        unordered_map<Node*, Node*> oldToNew;

        Node* curr = head;
        while(curr != nullptr){
            oldToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while(curr != nullptr){
            Node* clonedNode = oldToNew[curr];
            clonedNode->next = oldToNew[curr->next];
            clonedNode->random = oldToNew[curr->random];
            curr = curr->next;
        }
        return oldToNew[head];
    }
};
