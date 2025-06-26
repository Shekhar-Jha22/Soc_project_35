#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int x,y;
        cin>>x>>y;
        if((y-x)==1 || x>y ){
            if((x-y-8)%9==0)cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
        else cout<<"no"<<endl;
    }
}