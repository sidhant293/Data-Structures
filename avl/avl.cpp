#include<bits/stdc++.h>
using namespace std;

struct node{
int data;
node *left,*right;
int height;
};

int height(node *n){
    if(n==NULL)
        return 0;
    return n->height;
}

int balance(node *n){
    if(n==NULL)
        return 0;
    return height(n->left)-height(n->right);
}

node *newnode(int d){
    node *n=new node();
    n->data=d;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    return n;
}

node *rr(node * y){
    node *x=y->left;
    node *t=x->right;

    x->right=y;
    y->left=t;

    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    return x;
}

node *lr(node *x){
    node *y=x->right;
    node *t=y->left;

    y->left=x;
    x->right=t;

    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    return y;
}

node *insert(node *n ,int d){
    if(n==NULL)
        return newnode(d);
    else if(d>n->data)
        n->right=insert(n->right,d);
    else if(d<n->data)
        n->left=insert(n->left,d);
    else
        return n;

    n->height=1+max(height(n->left),height(n->right));
    int bal=balance(n);

    if(bal > 1 && d < n->left->data){
        return rr(n);
    }
    if(bal<-1 && d> n->right->data){
        return lr(n);
    }
    if(bal > 1 && d> n->left->data){
        n->left=lr(n->left);
        return rr(n);
    }
    if(bal <-1 && d< n->right->data){
        n->right=rr(n->right);
        return lr(n);
    }
    return n;
}

void pre_order(node *root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

int main(){

node * root=NULL;
root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 30);
root = insert(root, 40);
root = insert(root, 50);
root = insert(root, 25);

pre_order(root);
return 0;
}
