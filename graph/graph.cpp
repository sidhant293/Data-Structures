#include<bits/stdc++.h>
using namespace std;

stack<int> di;

void print_adj_list(vector<int> *a,int n){

cout<<endl;
vector<int> :: iterator j;

for(int i=1;i<=n-1;i++){
        cout<<i<<"->";
    for(j=a[i].begin(); j!=a[i].end(); j++){
        cout<<*j<<" ";
    }
    cout<<endl;
}
}

void bfs_trav(vector<int> *a,int n,int z){

queue<int> q;
vector<int> :: iterator i;
bool *visited = new bool[n];
    for(int i = 1; i <=n-1; i++)
        visited[i] = false;

        q.push(z);
        visited[z]=true;

        while(!q.empty()){
            int s=q.front();
            cout<<s<<" ";
            q.pop();
            for(i=a[s].begin(); i!=a[s].end(); i++){
                if(!visited[*i] ){
                    q.push(*i);
                    visited[*i]=true;
                }
            }
        }
}

void dfs_trav(vector<int> *a,bool visited[],int v){

    visited[v]=true;
    cout<<v<<" ";
    vector<int> :: iterator i;

    for(i=a[v].begin(); i!=a[v].end(); i++){
        if(!visited[*i]){
            dfs_trav(a,visited,*i);
        }
    }
}

bool dfs_iscyclic_unidirected(vector<int> *b,bool visited[],int parent,int v){

    if(!visited[v]){
        visited[v]=true;
    }

    vector<int> ::iterator i;
    for(i=b[v].begin(); i!=b[v].end(); i++){
            if(!visited[*i]){
        if(dfs_iscyclic_unidirected(b,visited,v,*i))
            return true;
            }

        else if(*i !=parent){
            return true;
        }
    }
    return false;
}

bool dfs_iscyclic_directed(vector<int> *a,bool visited[],bool rec_stack[],int v){

    if(!visited[v]){
        visited[v]=true;
        rec_stack[v]=true;
        di.push(v);
    }

    vector<int> ::iterator i;



    for(i=a[v].begin(); i!=a[v].end(); i++){
            if(!visited[*i]){
        if(dfs_iscyclic_directed(a,visited,rec_stack,*i))
            return true;
            }
            else if(rec_stack[*i]){
                    di.push(v);
                return true;
            }
    }

   return false;
}

int main(){
int n=7;   //total vertices +1

vector<int> *a=new vector<int>[n]; //directed graph
vector<int> *b=new vector<int>[n]; //undirected graph

a[1].push_back(2);
a[1].push_back(3);
a[2].push_back(4);
a[2].push_back(5);
a[3].push_back(5);
a[4].push_back(5);
a[4].push_back(6);
a[5].push_back(6);


b[1].push_back(2);
b[1].push_back(3);
b[2].push_back(1);
b[2].push_back(4);
b[2].push_back(5);
b[3].push_back(1);
b[3].push_back(5);
b[4].push_back(2);
b[4].push_back(5);
b[4].push_back(6);
b[5].push_back(2);
b[5].push_back(3);
b[5].push_back(4);
b[5].push_back(6);
b[6].push_back(4);
b[6].push_back(5);

print_adj_list(a,n);

print_adj_list(b,n);

int z=1;    //starting node
cout<<endl;
bfs_trav(a,n,z);
cout<<endl;

    {
        //for dfs
        bool *visited=new bool[n];
        for(int i=1;i<=n-1;i++)
            visited[i]=false;
        dfs_trav(a,visited,1);
    }

    {
        //to detect cycle in undirected graph
        bool *visited=new bool[n];
        for(int i=1;i<=n-1;i++){
            visited[i]=false;
            }

            cout<<endl<<dfs_iscyclic_unidirected(b,visited,-1,1);
    }

    {
        //to detect cycle in directed graph

        bool *visited=new bool[n];
         bool *rec_stack=new bool[n];
        for(int i=1;i<=n-1;i++){
            visited[i]=false;
            rec_stack[i]=false;
        }
            cout<<endl<<dfs_iscyclic_directed(a,visited,rec_stack,1)<<endl<<"cycle of directed printed in reverse ";
          int z=di.top();
          di.pop();
          cout<<z<<" ";
          while(!di.empty()){
                int y=di.top();
                di.pop();
          if(y == z)
            break;
            cout<<y<<" ";
          }
          cout<<z;
    }

return 0;
}


