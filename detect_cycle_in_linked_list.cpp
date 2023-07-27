bool detectcycle(node* &head){
        node* fast=head;
        node* slow=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
