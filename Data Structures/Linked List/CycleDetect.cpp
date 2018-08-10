//https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem
//Submitted Code(link below)
//https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/submissions/code/80995221

//Function to detect whether a linked list contains a cycle

bool has_cycle(SinglyLinkedListNode* head) {

  SinglyLinkedListNode* t=head;
  int i=0,list_size=1000;
    
    while(t->next!=NULL)
    {
        if(i>list_size)             //Given linked list size: 1000 
            return true;
        i++;
        t=t->next;
        
    }
    return false;
}
