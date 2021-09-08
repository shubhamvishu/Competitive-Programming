//https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return NULL;

        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>>pq;
        for(auto list : lists){
            if(list)
                pq.push({list->val,list});
        }

        ListNode * curr = NULL, * head = NULL;
        while(!pq.empty()){
            auto ele = pq.top();
            if(!curr) {
                curr = ele.second;
                head = curr;

            }
            else {
                curr->next = ele.second;
                curr= curr->next;
            }
            if(ele.second->next)
                    pq.push({ele.second->next->val,ele.second->next});
            pq.pop();
        }
        return head;
    }
};
