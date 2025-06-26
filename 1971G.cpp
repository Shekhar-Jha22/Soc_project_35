#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        unordered_map<int,vector<int>>mp;
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            mp[x].push_back(i);
            
        }

        for(int i=0;i<n;i++){
            if(v[i]%4==3){
                if(mp[v[i]-3].size())swap(v[i],v[mp[v[i]-3][0]]);
                
                else if(mp[v[i]-2].size())swap(v[i],v[mp[v[i]-2][0]]);
            
                else if(mp[v[i]-1].size())swap(v[i],v[mp[v[i]-1][0]]);
            
            }
            if(v[i]%4==2){
                if(mp[v[i]-2].size())swap(v[i],v[mp[v[i]-2][0]]);
            
                else if(mp[v[i]-1].size())swap(v[i],v[mp[v[i]-1][0]]);
            
            }
            if(v[i]%4==1){
                if(mp[v[i]-1].size())swap(v[i],v[mp[v[i]-1][0]]);
            
            }
            
        }
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}