//https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem
//Submitted code(link below)
//https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/submissions/code/79485614

//Function to Insert a node at the head of a linked list

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
	SinglyLinkedListNode* t=new SinglyLinkedListNode(data);
    if(!llist)
    {
        llist=t;
        return llist;
    }
    else{
        t->next=llist;
        llist=t;
        return llist;
    }

}
