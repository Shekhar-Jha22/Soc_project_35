#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int m;
        cin>>m;

        if(m%2==0){
            cout<<-1<<endl;
            continue;
        }
        else{
            map<int,int>mp;
            mp[3]=1;
            for(auto x:primes){
                if()
            }
            int count=1;
            for(int i=3;i<=m;i++){
                if(m%i==0){
                    while(m%i==0){
                        count+=(i-1)/2;
                        m/=i;
                    }
                }
            }
            cout<<count<<endl;
        }
    }
}