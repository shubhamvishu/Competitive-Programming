//https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem
//Submitted Code(link below)
//https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/submissions/code/79489039

//Function to find merge point of two Lists

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode* t1=head1;
    SinglyLinkedListNode* t2;
    while(t1!=NULL)
    {
        t2=head2;
        while(t2!=NULL)
        {
            if(t2->next==t1)
                return t1->data;
            t2=t2->next;
        }
        t1=t1->next;
    }
   return 0;
}
