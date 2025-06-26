#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int l,r;
        cin>>l>>r;
        if(l==r){
            if(l==1)cout<<1<<endl;
            else cout<<0<<endl;
        }
        else cout<<r-l<<endl;
    }
}