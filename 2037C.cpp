#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        if(n<5)cout<<-1<<endl;
        else if(n==5)cout<<"2 4 5 1 3"<<endl;
        else if(n==6)cout<<"6 2 4 5 1 3"<<endl;
        else{
            if(n%2==0){
                for(int i=n;i>0;i-=2){
                    if(i!=7)cout<<i<<" ";
                }
                cout<<7<<" ";
                for(int i=n-1;i>0;i-=2){
                    if(i!=7)cout<<i<<" ";
                }
                cout<<endl;
            }
            if(n%2==1){
                for(int i=n-1;i>0;i-=2){
                    if(i!=7)cout<<i<<" ";
                }
                cout<<7<<" ";
                for(int i=n;i>0;i-=2){
                    if(i!=7)cout<<i<<" ";
                }
                cout<<endl;
            }
        }
    }
}