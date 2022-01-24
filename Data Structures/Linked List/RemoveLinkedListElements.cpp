//https://leetcode.com/problems/remove-linked-list-elements/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        while(head && head->val==val){
            head=head->next;
        }
        ListNode* t1=head, *t2 = NULL;
        if(t1) t2=t1->next;
        while(t2!=NULL){
            if(t2->val!=val){
                t1->next=t2;
                t1=t1->next;
            }
            t2=t2->next;
        }
        if(t1) t1->next=NULL;
        return head;
    }
};
