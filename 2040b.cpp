#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int x=4,turn=2;
        if(n==1)cout<<1<<endl;
        else if(n<=4)cout<<2<<endl;
        else{
            while(x<n){
                x=2*(x+1);
                turn++;
            }
            cout<<turn<<endl;
        }
    }
}