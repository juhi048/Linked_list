#include<iostream>
#include"bits/stdc++.h"
using namespace std;
class node{
    public:
    node *next;
    int data;

    node(int val){
    data=val;
    next=NULL;
    }
};

void insertAtTail(node* &head,int val){
    node *n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head,int val){
    node *n= new node(val);
    n->next=head;
    head=n;
}

void deletion(node* &head,int val){
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;

    delete todelete;
}

void display(node* &head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node * head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    insertAtHead(head,0);
    display(head);
    deletion(head,5);
    deletion(head,3);
    display(head);
    deleteAtHead(head);
    display(head);
return 0;
}
