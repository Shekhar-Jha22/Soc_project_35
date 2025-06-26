#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        unordered_map<int,int>mp;
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int current=v[0];
        for(int i=0;i<v.size();i++){
            if(mp[current]==2){
                current++;
            }
            if(v[i]<=current){
                v[i]=current;
                mp[current]++;
            }
            else if(v[i]>current){
                current=v[i];
                mp[current]++;
            }
        }
        bool cond=true;
        for(auto x:mp){
            if(x.second%2==1)cond=false;
        }
        if(cond)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}