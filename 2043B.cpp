#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n,x;
        cin>>n>>x;
        bool min=(n>2);
        cout<<1<<" ";

        if(min || x%3==0)cout<<3<<" ";
        if(x==5)cout<<5<<" ";
        if(min || x==7)cout<<7<<" ";
        if(x==9)cout<<9<<" ";
        else if(x%3==0 && min)cout<<9<<" ";
        else if(n>5)cout<<9<<" ";

        cout<<endl;

    }
}