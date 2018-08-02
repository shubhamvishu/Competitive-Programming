//https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem
//Submitted code(link below)
//https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/submissions/code/79486950

//Function to Insert a node at a specific position in a linked list

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
  SinglyLinkedListNode* t=new SinglyLinkedListNode(data);
    if(position==0)
    {
        t->next=head;
        head=t;
        return head;
    }
    else{
        int c=0;
        SinglyLinkedListNode* t1=head;
        while((position-c)>1)
        {
            t1=t1->next;
            c++;
        }
        t->next=t1->next;
        t1->next=t;
        return head;
    }

}
