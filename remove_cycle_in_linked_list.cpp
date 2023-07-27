void removecycle(node* &head){
        node* fast=head;
        node* slow=head;
        do{
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);

        fast=head;
        while (slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=NULL;
        

    }
