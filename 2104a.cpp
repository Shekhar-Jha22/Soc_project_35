#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        double a,b,c;
        cin>>a>>b>>c;
        double x =(a+b+c)/3;
        if(ceil(x)!=x)cout<<"no"<<endl;
        else if(a>x || b>x)cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
}

