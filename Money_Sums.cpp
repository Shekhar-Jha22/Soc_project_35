#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    map<int,int>mp,mp1;
    for(int i=0;i<n;i++){
        mp1=mp;
        if(i!=0){
            mp[v[i]]++;
            for(auto x:mp1){
                mp[x.first+v[i]]++;
            }
        }
        else mp[v[i]]++;
    }
    cout<<mp.size()<<endl;
    for(auto x:mp){
        cout<<x.first<<" ";
    }
    cout<<endl;
}