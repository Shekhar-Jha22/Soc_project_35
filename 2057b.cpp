#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        
        vector<int>v;
        vector<pair<int,int>>v1;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(v1.size()==0)v1.push_back({1,v[0]});
            else{
                if(v1.back().second==v[i])v1.back().first++;
                else v1.push_back({1,v[i]});
            }
        }
        if(k>=n){
            cout<<1<<endl;
            continue;
        }
        sort(v1.begin(),v1.end());
        int posn=0;
        bool found=false;
        for(int i=0;i<v1.size();i++){
            k-=v1[i].first;
            if(k==0){
                posn=i;
                found=true;
            }
            else if(k<0){
                posn=i-1;
                found=true;
                
            }
            if(found)break;
        }
        if(!found){
            cout<<1<<endl;
            continue;
        }
        else {
            cout<<v1.size()-posn-1<<endl;
            continue;
        }
        
        
    }
}