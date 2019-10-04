#include<bits/stdc++.h>
using namespace std;

struct node{
int data;
node * x;
};

node* XOR (node *a, node *b)
{
    return (node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

node * head=nullptr;
node * tail=nullptr;
node *Prev=nullptr;
node *pprev=nullptr;
void ins(int d){
    node *temp=new (node);
    temp->data=d;
    temp->x=nullptr;
    if (head==nullptr){
        head=temp;
        Prev=temp;
        pprev=nullptr;

    }else{
        Prev->x=XOR(temp,pprev);
        pprev=Prev;
        Prev=temp;
    }
    tail=temp;
}

void disp(){
    node *curr = head;
    node *prev = nullptr;
    node *next;

    cout << "Following are the nodes of Linked List: \n";

    while (curr != nullptr)
    {
        cout<<curr->data<<" ";
        next = XOR (prev, curr->x);

        prev = curr;
        curr = next;
    }
}

int main(){

ins(10);
ins(20);
ins(30);
ins(40);
ins(50);

disp();

return 0;
}
