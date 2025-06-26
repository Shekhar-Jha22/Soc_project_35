#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        bool condition=true;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if((x-2*max(i,n-1-i))<=0)condition=false;
        }
        if(condition)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}