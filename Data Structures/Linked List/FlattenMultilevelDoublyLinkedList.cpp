//https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

class Solution {
public:
    Node* flatten(Node* head) {
        flattenList(head);
        return head;
    }
    Node* flattenList(Node* head){
        if(head==NULL) return NULL;
        Node* temp = head;
        Node* curr = temp;

        if(temp->child!=NULL){
            Node* remain = temp->next;
            temp->next = temp->child;
            temp->child->prev = temp;
            temp->child = NULL;
            curr = flattenList(temp->next);
            if(remain!=NULL){
                curr->next = remain;
                remain->prev = curr;
                return flattenList(remain);
            }
            return curr;
        }
        else if(temp->next!=NULL){
            return flattenList(temp->next);
        }
        else {
            return temp;
        }
    }
};
