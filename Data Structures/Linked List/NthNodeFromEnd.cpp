//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
    bool b=false;
public:
    int findReq(ListNode* t1,ListNode* t2,int n)
    {
        if(t2==NULL)
            return 1;
        int i=findReq(t1->next,t2->next,n);
        if(i==n)
        { t1->next=t2->next;
         b=true;
        }
        return i+1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t1=head;
        ListNode* t2=head->next;
        if(head->next==NULL)
        {
            head=head->next;
            return head;
        }
        findReq(t1,t2,n);
        if(!b)
            head=head->next;
        return head;
    }
};
