//https://leetcode.com/problems/swap-nodes-in-pairs/


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

    
    ListNode* swapPairs(ListNode* head) {
       
        ListNode* temp=head;
        vector<ListNode*>v1;
        int c=0;
        if(head==NULL || head->next==NULL)
            return head;
        while(temp!=NULL)
        {
            c++;
            v1.push_back(temp);
            temp=temp->next;
        }
        for(int i=1;i<c;i+=2)
        {
            cout<<v1[i]->val;
            v1[i]->next=v1[i-1];  
        }
        for(int i=0;i<c;i+=2)
        {
            if((i+3)<c)
                v1[i]->next=v1[i+3];
            else{
                if((i+2)<c)
                v1[i]->next=v1[i+2];
                else
                    v1[i]->next=NULL;
                }
        }
        return v1[1];
    }
};