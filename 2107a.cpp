#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t,maxi=-1,maxind=-1;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        bool cond=true;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x>maxi){
                maxi=x;
                maxind=x;
            }
            if(i!=0){
                if(x!=maxi)cond=false;
            }
        }
        if(cond)cout<<"no"<<endl;
        else{
            cout<<"yes"<<endl;
            for(int i=0;i<n;i++){
                if(i==maxind)cout<<1<<" ";
                else cout<<2<<" ";
            }
            cout<<endl;
        }
        
    }
}