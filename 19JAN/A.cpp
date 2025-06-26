#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a1,a2,a3,a4,a5;
        cin>>a1>>a2>>a4>>a5;

        if(2*a2+a1==a4)a3=a1+a2;
        else if(a2+a5==2*a4)a3=a5-a4;
        else a3=a1+a2;

        int x1=0,x2=0,x3=0;
        if(a1+a2==a3)x1=1;
        if(a2+a3==a4)x2=1;
        if(a3+a4==a5)x3=1;

        if(x1==1 && (x2==1 && x3==1))cout<<3<<endl;
        else if(x2==1 && (x1==1 || x3==1))cout<<2<<endl;
        else if(x1==1 && x3==1)cout<<2<<endl;
        else cout<<1<<endl;

    }
}