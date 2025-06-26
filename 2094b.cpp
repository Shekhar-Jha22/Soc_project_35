#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(d+b-a>=0)
    cout<<c<<" "<<d+b-a<<endl;
    else cout<<c-(d+b-a)<<" "<<0<<endl;
    }
}