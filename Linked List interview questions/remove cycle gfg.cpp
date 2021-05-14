 void removeLoop(Node* head)
    {
        // code here
        Node* slow=head;
        Node* fast=head;
        if(head==NULL)
        return;
        Node* last;
        while(fast!=NULL && fast->next!=NULL)
        {
            if(slow->next==head)
            last=slow;                          // specially store for case when linkedlist length== cycle length
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast && slow==head)
            {
                last->next=NULL;
                break;
            }
            else if(slow==fast)
            {
                fast=head;
                while(fast->next!=slow->next)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                slow->next=NULL;
                break;
            }
        }
        // just remove the loop without losing any nodes
    }