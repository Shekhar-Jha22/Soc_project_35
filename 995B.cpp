#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        int x;
        x=n/(a+b+c);
        n=n%(a+b+c);
        if(n==0)cout<<3*x<<endl;
        else{
            if(n<=a)cout<<3*x+1<<endl;
            else if(n<=a+b)cout<<3*x+2<<endl;
            else if(n<a+b+c)cout<<3*x+3<<endl;
        }
        
    }
}