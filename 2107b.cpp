#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        unordered_map<int,int>mp;
        int n,k,maximum=0,minimum=1e9+7;
        long long sum=0;
        cin>>n>>k;
        vector<int>app(n,0);
        for(int i=0;i<n;i++){
            cin>>app[i];
            sum+=app[i];
            maximum=max(maximum,app[i]);
            minimum=min(minimum,app[i]);
            mp[app[i]]++;
        }
        if(maximum-minimum-1>k ||(mp[maximum]>1 && maximum-minimum>k))cout<<"Jerry"<<endl;
        else if(sum%2)cout<<"Tom"<<endl;
        else cout<<"Jerry"<<endl;
    }
}