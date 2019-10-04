#include<iostream>
#include<map>
#include<bits/stdc++.h>
#include<string>
                       // Program that removes duplicate values from a STRING
using namespace std;

int main(){
string s;
cin>>s;
set<char>m;
set<char> :: iterator itr;
for(int i=0;i<s.length();i++){

    if(m.find(s[i]) == m.end()){   //if element not present
        m.insert(s[i]);
    }
}


    cout<<endl;

for(itr = m.begin(); itr != m.end(); itr++)
    cout<<*itr<<" ";

return 0;
}
