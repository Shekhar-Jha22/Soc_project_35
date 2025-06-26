#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int odd=0,even=0;

        for(int i=0;i<n;i++){
            long long int x;
            cin>>x;

            if(x%2==1)odd++;
            else even++;
        }

        if(n==1 ){
            if( odd==1)cout<<0<<endl;
            else cout<<1<<endl;
        }
        else if(even==0)cout<<odd-1<<endl;
        else if(odd==0)cout<<1<<endl;
        else cout<<1+odd<<endl;
    }
}