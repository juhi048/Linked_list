#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        next=NULL;
        data=val;
    }
};

void insertAtTAil(node* &head , int val){
    node* n=new node (val);
    if(head==NULL){
        head=n;
        return; 
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;   
    }
    temp->next=n;
}

void insertAtHead(node* &head,int val){
    node* n= new node (val);
    n->next=head;
    head=n;
}

node* reversek(node* &head,int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next=reversek(nextptr,k);
    }
    return prevptr;
}

void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    insertAtTAil(head,5);
    insertAtTAil(head,6);
    insertAtTAil(head,7);
    insertAtTAil(head,8);
    display(head);
    
    int k = 2;
    node* newhead = reversek(head,2);
    display(newhead);
 
return 0;
}
