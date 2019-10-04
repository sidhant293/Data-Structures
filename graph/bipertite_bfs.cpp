#include<iostream>
#include<vector>
using namespace std;

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

bool isbipertite(vector<int> *a,vector<bool> &visited,vector<bool> &colour,int v){

    vector<int> :: iterator i;

    for(i=a[v].begin(); i!=a[v].end(); i++){
        if(!visited[*i]){
            visited[*i]=true;
            colour[*i]=!colour[v];
            if(!isbipertite(a,visited,colour,*i))
                return false;
        }
        else if(colour[*i]==colour[v])
            return false;
    }

return true;
}

int main(){
int n=6;
vector<int> *a=new vector<int>[n+1];
a[1].push_back(2);
a[1].push_back(3);
a[2].push_back(4);
a[3].push_back(5);
a[4].push_back(6);
a[5].push_back(6);

print_adj_list(a,n);

vector<bool> visited(n+1);
vector<bool> colour(n+1);

colour[1]=0;
visited[1]=true;
cout<<endl<<isbipertite(a,visited,colour,1);

return 0;
}
