//https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem
//Submitted code(link below)
//https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/submissions/code/79485295

//Function to Insert a node at the tail of a linked list

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
	SinglyLinkedListNode* t=new SinglyLinkedListNode(data);
   if(!head)
   {
       head=t;
       return head;
   }
    else{
         SinglyLinkedListNode* t1=head;
    while(t1->next!=NULL)
    {
        t1=t1->next;
    }
        t1->next=t;
        return head;
}
        
    }
