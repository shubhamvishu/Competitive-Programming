//https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem
//Submitted Code(link below)
//https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/submissions/code/79492024


//Function to Insert a Node Into a Sorted Doubly Linked List

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* t=new DoublyLinkedListNode(data);
    DoublyLinkedListNode* t1=head;
    if(!t1)
    {
       head=t;
        return head;
    }
    else if(t1->next==NULL)
    {
        if(data>=t1->data)
        {
            t1->next=t;
            t->prev=t1;
        }
        else{
            t->next=t1;
            t1->prev=t;
            head=t;
        }
        return head;
    }
    else{
        if(data<=head->data)
        {
            t->next=head;
            head->prev=t;
            head=t;
        }
        else{
            t1=head->next;
            while(data>t1->data && t1->next!=NULL)
            {
                t1=t1->next;
            }
            if(data>t1->data)
            {
                t1->next=t;
                t->prev=t1;
            }
            else{
                t->next=t1;
                t->prev=t1->prev;
                t1->prev->next=t;
                t1->prev=t;
            }
            
        }

        return head;
    }

}
