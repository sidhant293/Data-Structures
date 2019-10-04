#include<iostream>
using namespace std;

struct node{
int data;
struct node *prev;
struct node *next;
}*head,*tail;

node *create_node(int);
void insert_at_beg();
void print();
void print_rev();
void insert_sorted();

int main(){

   head=NULL;
   tail=NULL;
   insert_at_beg();
   insert_at_beg();
   insert_at_beg();
   insert_sorted();
   print();
   print_rev();

return 0;
}

node *create_node(int x){

    node *Nnode= new(struct node);
    Nnode->data=x;
    Nnode->prev=NULL;
    Nnode->next=NULL;
    return Nnode;
}

void insert_at_beg(){
    int value;
    cout<<"enter value ";
    cin>>value;
    node *temp=create_node(value);
    if(head==NULL){
        head=temp;
        tail=head;
        return;
    }
    head->prev=temp;
    temp->next=head;
    head=temp;
}

void print(){

    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void print_rev(){

    node *temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}

void insert_sorted(){

    int value;
    cout<<"enter value ";
    cin>>value;
    node *Node=create_node(value);
    node *temp=head;

    if(temp->prev==NULL && Node->data < temp->data){
        Node->next=temp;
        Node->next->prev=Node;
        head=Node;
        return;
    }else{

    while(temp->next!=NULL){
        if( Node->data < temp->data){
            Node->next=temp;
            temp->prev->next=Node;
            Node->prev=temp->prev;
            temp->prev=Node;
            return;
       }
       temp=temp->next;
    }
        if( Node->data < temp->data){
            Node->next=temp;
            temp->prev->next=Node;
            Node->prev=temp->prev;
            temp->prev=Node;
            return;
        }else{
            temp->next=Node;
            Node->prev=temp;
            tail=Node;
            return;

        }
  }
}
