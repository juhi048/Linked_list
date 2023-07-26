#include<iostream>
#include"bits/stdc++.h";
using namespace std;
class node{
    public:
    int data;
    node* next;

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
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head,int val){
    node * n =new node (val);
    n->next=head;
    head=n;
}

node* reverse_Linked_list(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}
void display(node* head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}
int main(){
    node* head=NULL;
    insertAtTail(head,7);
    insertAtTail(head,8);
    insertAtTail(head,9);
    insertAtTail(head,10);
    display(head);
    insertAtHead(head,6);
    insertAtHead(head,5);
    display(head);
    node* newhead=reverse_Linked_list(head);
    display(newhead);

 
return 0;
}
