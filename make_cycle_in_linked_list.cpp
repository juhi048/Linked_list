void makecycle(node* &head,int pos){
        node* temp=head;
        node* startnode;

        int count=1;
        while(temp->next!=NULL){
            if(count==pos){
                startnode=temp;
            }
            temp=temp->next;
            count++;
        }
        temp->next=startnode;
    }
