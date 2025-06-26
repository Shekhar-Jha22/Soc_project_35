#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        unordered_map<int,int>mp;
        vector<pair<int,int>>v;

        for(int i=0;i<n;i++){
            int first,second;
            

            cin>>first>>second;
            if(first==second)mp[first]++;

            v.push_back({first,second});
        }
        for(int i=0;i<n;i++){
            bool cond=true;
            if(v[i].first!=v[i].second){
                for(int j=v[i].first;j<=v[i].second;j++){
                    if(mp[j]==0){
                        cout<<1;
                        cond=false;
                        break;
                    }
                }
                if(cond)cout<<0;
            }
            else {
                if(mp[v[i].first]>1)cout<<0;
                else cout<<1;
            }
        }
        cout<<endl;
    }
}