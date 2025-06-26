#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        long long int n;
        cin>>n;
        unordered_map<int,int>mp;
        vector<pair<int,int>>v;
        for(long long int i=0;i<n;i++){
            mp[i+1]=1;
        }
        for(long long int i=0;i<n;i++){
            int x;
            cin>>x;
            
            if(mp[x]==1){
                mp[x]=0;
                v.push_back({i,x});
            }
            
            
        }
        sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                cout<<v[i].second<<" ";
            }
            for(int i=1;i<=n;i++){
                if(mp[i]==1)cout<<i<<" ";
            }
            cout<<endl;
    }
}