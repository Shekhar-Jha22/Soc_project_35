#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int x,y;
        cin>>x>>y;
        int p=(x-y)%9;
        if(y==x)cout<<"no"<<endl;
        
        else if(y<x && p==8)cout<<"yes"<<endl;
        else if(y<x && p!=8)cout<<"no"<<endl;
        else if(y>x && y-x==1)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
        
    }
}