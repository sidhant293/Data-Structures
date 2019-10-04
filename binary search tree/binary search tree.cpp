#include<iostream>
#include<queue>
using namespace std;

struct BstNode{
int data;
BstNode* left;
BstNode* right;
};

BstNode* create_node(int d);
BstNode* insert_node(BstNode* root,int d);
bool search_node(BstNode* root,int d);
int find_min(BstNode* root);
int find_height(BstNode* root);
void level_oreder(BstNode* root);
int store_in_array(BstNode *root,int a[],int i);

int main(){

    int a[50];

BstNode* root=NULL;
root=insert_node(root,15);
root=insert_node(root,10);
root=insert_node(root,8);
root=insert_node(root,21);
root=insert_node(root,51);
root=insert_node(root,100);

cout<<search_node(root,50)<<endl;
cout<<find_min(root)<<endl;
cout<<find_height(root)<<endl;
level_oreder(root);
cout<<endl;
int j=store_in_array(root,a,0);
for(int i=0;i<6;i++)
    cout<<a[i]<<" ";

return 0;
}

BstNode* create_node(int d){
 BstNode* newnode=new BstNode();
 newnode->data=d;
 newnode->right=NULL;
 newnode->left=NULL;
 return newnode;
}


int store_in_array(BstNode *root,int a[],int i){

    if(root == NULL)
        return i;

    i=store_in_array(root->left,a,i);
    a[i++]=root->data;
    return store_in_array(root->right,a,i);
}

BstNode* insert_node(BstNode* root,int d){

 if(root == NULL){
    root=create_node(d);
 }else if(d <= root->data){
    root->left=insert_node(root->left,d);
 }else{
    root->right=insert_node(root->right,d);
 }
    return root;
}

bool search_node(BstNode* root,int d){
    if(root ==NULL){
        return false;
    }
    if(root->data ==d){
        return true;
    }else{
        if(d <= root->data){
            return search_node(root->left,d);
        }else{
            return search_node(root->right,d);
        }
    }
}

int find_min(BstNode* root){

 if(root->left == NULL){
    return root->data;
 }
 find_min(root->left);

}

int find_height(BstNode* root){

    if(root == NULL){return -1;}

    return max(find_height(root->left),find_height(root->right))+1;

}

void level_oreder(BstNode* root){

   queue <BstNode*> q;
   q.push(root);
   while(!q.empty()){
        BstNode* current=q.front();
        cout<<current->data<<" ";
        if(current->left!= NULL)
            q.push(current->left);
        if(current->right!=NULL)
            q.push(current->right);
        q.pop();
   }

}
