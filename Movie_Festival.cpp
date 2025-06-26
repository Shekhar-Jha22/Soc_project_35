#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>v(n,{0,0});

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[i]=make_pair(a,b);
    }

    sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    });
    int count=1,end=v[0].second;
    for(int i=1;i<n;i++){
        if(v[i].first>=end){
            end=v[i].second;
            count++;
        }
    }
    cout<<count<<endl;
}