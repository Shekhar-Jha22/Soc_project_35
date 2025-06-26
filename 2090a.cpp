#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int x,y,a;
        cin>>x>>y>>a;
        int k=a%(x+y);
        if(k<x)cout<<"NO"<<endl;
        else cout<<"yes"<<endl;
    }
}