#include<iostream>
using namespace std;
int main(){

int n;
cin>>n;
int **p=new int* [n];
for(int i=0;i<n;i++)
    p[i]=new int[n];
cout<<endl;
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>p[i][j];

    cout<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<p[i][j];
        }
        cout<<endl;
    }

    delete[]p[i]
return 0;
}
