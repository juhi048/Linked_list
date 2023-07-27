#include<iostream>
#include"bits/stdc++.h"
using namespace std;
class node{
    public:
    int data;
    node *next;

    node(int val){
        data=val;
        next=NULL;
    }

};

    void insertAtTail(node* &head,int val){
        node* n=new node(val);

        if (head==NULL){
            head=n;
            return ;
        }
        node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;

    }

    void insertAtHead(node* &head,int val){
        node*n=new node(val);

        n->next=head;
        head=n;
    }
    
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


    void display(node* head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }


int main(){
    node* head=NULL;
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    insertAtTail(head,9);
    insertAtTail(head,10);
    insertAtTail(head,11);
    display(head);
    makecycle(head,5);
    // display(head);
    cout<<detectcycle(head)<<endl;
    removecycle(head);
    cout<<detectcycle(head)<<endl;
    display(head);
return 0;
}
