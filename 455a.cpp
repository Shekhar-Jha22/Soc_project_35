#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
int max_sum(vector<int>v,int posn,unordered_map<int,int>mp){
    if(posn<0)return 0;
    if(posn==0 )return mp[v[posn]];
    if(posn==1)return max(mp[v[1]],mp[v[0]]);
    return max(max_sum(v,posn-2,mp)+mp[v[posn]],max_sum(v,posn-1,mp));

}
int main(){
    int n;
    cin>>n;
    vector<int>v;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(mp[x]==0)v.push_back(x);
        mp[x]+=x;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.back();i++){
        
        if(mp[i]!=0)continue;
        else mp[i]=0;
    }
    
    cout<<max_sum(v,v.size()-1,mp)<<endl;
}