//https://leetcode.com/problems/split-linked-list-in-parts/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        int base_size = size/k;
        int base_inc = size%k;
        int i = 1;
        temp = head;
        vector<ListNode*> result;
        while(i<=k){
            int ll_size = base_size;
            if(i<=base_inc) ll_size++;
            ListNode* t = temp;
            while((ll_size-1)>0){
                temp = temp->next;
                ll_size--;
            }
            ListNode* tail = temp;
            if(temp) temp = temp->next;
            if(tail) tail->next = NULL;
            result.push_back(t);
            i++;
        }
        return result;
    }
};
