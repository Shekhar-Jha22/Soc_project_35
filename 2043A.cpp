#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long int n;
        cin>>n;
        long long int coins=1;
        while(n>=4){
            coins=2*coins;
            n=n/4;
        }
        cout<<coins<<endl;
    }
}