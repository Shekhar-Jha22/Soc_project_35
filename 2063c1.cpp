#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int dfs(int i,vector<bool>&visited,int max1,vector<int>adj[]){
        visited[i]=true;
        int maxi=max1;
        if(adj[i].size()>maxi)maxi=adj[i].size();
        for(auto u:adj[i]){
            if(!visited[u])maxi=max(dfs(u,visited,maxi,adj),maxi);
        }
    return maxi;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> adj[n];
        vector<pair<int,int>>ed(n-1,{0,0});
        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            adj[a-1].push_back(b);
            adj[b-1].push_back(a);
            ed.push_back({a,b});
        }
        int maxind=0,max=0;
        for(int i=0;i<n;i++){
            if(adj[i].size()>max){
                max=adj[i].size();
                maxind=i;
            }
        }
        int max2=0;
        vector<bool>visited(n,true);
        max2=dfs(maxind,visited,max2,adj);
        
    }
}