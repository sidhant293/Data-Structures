#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void print_adj_list(vector<int> *a,int n){

cout<<endl;
vector<int> :: iterator j;

for(int i=0;i<n;i++){
        cout<<i<<"->";
    for(j=a[i].begin(); j!=a[i].end(); j++){
        cout<<*j<<" ";
    }
    cout<<endl;
}
}

void dfs_trav(vector<int> *a,bool visited[],int v,stack<int> &s){

    visited[v]=true;
    cout<<v<<" ";
    vector<int> :: iterator i;

    for(i=a[v].begin(); i!=a[v].end(); i++){
        if(!visited[*i]){
            dfs_trav(a,visited,*i,s);
        }
    }

    s.push(v);
}

void transpose_graph( vector<int> *a ,int n,vector<int> *g){

for (int j = 0; j < n; j++)
    {
        vector<int>::iterator i;
        for(i = a[j].begin(); i != a[j].end(); ++i)
        {
            g[*i].push_back(j);
        }
    }

    print_adj_list(g,n);
}


int main(){

int n=5;
vector<int> *a=new vector<int>[n];
vector<int> *g=new vector<int>[n];

a[0].push_back(2);
a[0].push_back(3);
a[1].push_back(0);
a[2].push_back(1);
a[3].push_back(4);

print_adj_list(a,n);

stack<int> s;
stack<int> j;

{
bool *visited=new bool[n];
    for(int i=0;i<n;i++)
        visited[i]=false;

    for(int i=0;i<n;i++)
        if(visited[i]==false)
            dfs_trav(a,visited,i,s);
}

cout<<endl;
transpose_graph(a,n,g);

bool *visited=new bool[n];
    for(int i=0;i<n;i++)
        visited[i]=false;

while(!s.empty()){

    int v=s.top();
    s.pop();

    if(visited[v]==false){
        dfs_trav(g,visited,v,j);
        cout<<endl;
    }
}

return 0;
}
