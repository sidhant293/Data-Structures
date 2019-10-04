#include<iostream>
#define max 5
using namespace std;
struct node{
int fron_t;
int rear;
int data[max];
}q;

void create();
void enQueue();
void deQueue();
bool emptyQueue();
bool fullQueue();
void printQueue();

int main(){

cout<<"maximum size of queue is "<<max<<endl;
create();
int a;
do{
    cout<<"1. Enqueue"<<endl<<"2. Dequeue"<<endl<<"0. Exit"<<endl;
    cin>>a;
    if(a==1)
        enQueue();
    else if(a==2)
        deQueue();
    printQueue();
}while(a);

return 0;
}

void create(){

    q.fron_t=-1;
    q.rear=-1;
}

void enQueue(){

    if(fullQueue()){
        cout<<endl<<"Queue is already full"<<endl;
    }else{
    int x;
    cout<<"enter element ";
    cin>>x;
    cout<<endl;
    if( emptyQueue() ){
        q.fron_t=0;
        q.rear=0;
    }else{
        q.rear=(q.rear+1)%max;
    }
    q.data[q.rear]=x;
    }
}

bool fullQueue(){
    return (q.rear+1)% max ==q.fron_t ? true:false;
}

void printQueue(){

    cout<<endl;

    int count = (q.rear+max-q.fron_t)%max + 1;
		for(int i = 0; i <count; i++)
		{
			int index = (q.fron_t+i) % max;
			cout<<q.data[index]<<" ";
		}

    cout<<endl;
}

void deQueue(){

    if(emptyQueue()){
        cout<<endl<<"Queue already empty"<<endl;
    }else if(q.fron_t==q.rear){
        q.fron_t=-1;
        q.rear=-1;
    }else{
        q.fron_t=(q.fron_t+1)%max;
    }

}

bool emptyQueue(){
    return (q.fron_t == -1 && q.rear == -1);
}
