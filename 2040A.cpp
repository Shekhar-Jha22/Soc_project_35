#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            mp[x%k]++;
        }
        int p=0;
        bool cond=true;
        for(int i=0;i<k;i++){
            if(mp[i]==1){
                cout<<"yes"<<endl;
               p=i;
                cond=false;
            }
        }
        if(!cond)cout<<""
        if(cond)cout<<"no"<<endl;
    }
}