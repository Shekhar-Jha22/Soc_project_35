#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int sum=0,sum1=0;

    for(int i=0;i<t;i++){
        int x,y,z;
        cin>>x>>y>>z;
        sum=x+y+z;

        if(sum>=2)sum1+=1;
    }
    cout<<sum1;
}