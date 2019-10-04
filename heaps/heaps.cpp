#include<iostream>
using namespace std;

void swap(int *x, int *y){
int temp=*x;
*x=*y;
*y=temp;
}

void max_heapify (int a[ ], int i, int n)
{
    int left = 2*i  ;                 //left child  1 4 3 7 8 9 10
    int right = 2*i +1  ;         //right child
    int largest;
    if(left<= n and a[left] > a[i] )
          largest = left;
    else
         largest = i;
    if(right <= n and a[right] > a[largest] )
        largest = right;
    if(largest != i )
    {
        swap (a[i] , a[largest]);
        max_heapify (a, largest,n);
    }
 }

 void build_maxheap (int a[ ],int n)
{
    for(int i = n/2 ; i >= 1 ; i-- )
    {
        max_heapify (a, i,n) ;
    }
}

int delete_item(int a[],int n){
        a[1]=a[n];
        n--;
        max_heapify(a,1,n);
        return n;
}

int insert_item(int a[],int n, int i){
    n++;
    a[n]=i;
    int l=n;
    while(l>1 && a[l/2]<a[l]){
        swap(a[l/2],a[l]);
        l=l/2;
    }
    return n;
}

void heap_sort(int a[ ],int n)
{
    int heap_size = n;
    build_maxheap(a,n);
    for(int i = n; i>=2 ; i-- )
    {
        swap(a[ 1 ], a[ i ]);
        heap_size = heap_size-1;
        max_heapify(a, 1, heap_size);
    }
}

int main(){

int n; //size of heap
cin>>n;

int *a=new int(n);
for(int i=1;i<=n;i++)
    cin>>a[i];

cout<<endl;

build_maxheap(a,n);

for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";

n=delete_item(a,n);

cout<<endl;

for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";

cout<<endl;

n=insert_item(a,n,10);

for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";

    cout<<endl;

    heap_sort(a,n);

    for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";

return 0;
}
