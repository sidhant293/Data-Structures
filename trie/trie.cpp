#include<bits/stdc++.h>
using namespace std;

struct TNode{
    char data;
    TNode *children[26];
    bool terminal;

    TNode(char d){
        data=d;
        terminal=false;
        for(int i=0;i<26;i++) children[i]=NULL;
    }
};

void insert(TNode *root,string word){
    if(word.length()==0){
        root->terminal=true;
        return;
    }

    TNode *child;
    int index=word[0]-'a';

    if(root->children[index]!=NULL){
        child=root->children[index];
    }else{
        child=new TNode(word[0]);
        root->children[index]=child;
    }
    insert(child,word.substr(1));
}

bool search(TNode *root,string word){
    if(word.length()==0){
        return root->terminal;
    }
    int index=word[0]-'a';
    TNode *child;
    if(root->children[index]!=NULL){
        child=root->children[index];
    }else{
    return false;
    }
    return search(child,word.substr(1));
}

void remove(TNode *root,string word){
    if(word.length()==0){
        root->terminal=false;
        return;
    }
    int index=word[0]-'a';
    TNode *child;

    if(root->children[index]!=NULL){
            child=root->children[index];
    }else{
    return ;}

    remove(child,word.substr(1));

    if(child->terminal==false){
        for(int i=0;i<26;i++){
            if(child->children[i]!=NULL)
                return;
        }
        delete child;
        root->children[index]=NULL;
    }
}

int main(){

    TNode *root=new TNode('\0');
    insert(root,"sid");
    insert(root,"apple");
    insert(root,"app");
    insert(root,"sidhant");
    insert(root,"bye");
    insert(root,"ok");

    cout<<search(root,"sid")<<endl;
    cout<<search(root,"sidhant")<<endl;
    cout<<search(root,"app")<<endl;
    cout<<search(root,"apple")<<endl;

    remove(root,"sid");
    remove(root,"apple");


    cout<<search(root,"sid")<<endl;
    cout<<search(root,"sidhant")<<endl;
    cout<<search(root,"app")<<endl;
    cout<<search(root,"apple")<<endl;

return 0;
}
