#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        mp[a]++;
        mp[b+1]--;
    }
    v.push_back(0);
    for(auto x:mp){
        v.push_back(x.second);
    }
    for(int i=1;i<v.size();i++)v[i]+=v[i-1];

    cout<<*max_element(v.begin(),v.end())<<endl;;
}