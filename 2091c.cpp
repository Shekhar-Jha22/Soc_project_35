#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        if(n%2==0)cout<<-1<<endl;
        else{
            for(int i=0;i<(n+1)/2;i++){
                cout<<2*i+1<<" ";
                
            }
            for(int i=1;i<(n+1)/2;i++){
                cout<<2*i<<" ";
                
            }
            cout<<endl;
        }
    }
}