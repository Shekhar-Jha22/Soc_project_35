#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<s.size();i++){
            v.push_back({s[i]-'0'-i,{s[i]-'0',i}});
            
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        for(int i=0;i<s.size();i++){
            if(v[i].second.second<=i)cout<<v[i].second.first;
            else cout<<v[i].second.first-v[i].second.second+i;
        }
        cout<<endl;
    }
}