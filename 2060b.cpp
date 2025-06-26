#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        unordered_map<int,int>mp;
        vector<vector<int>>v1,v2;
        
        for(int i=0;i<n;i++){
            vector<int>v;
            for(int i=0;i<m;i++){
                int x;
                cin>>x;
                v.push_back(x);
            }
            sort(v.begin(),v.end());
            v1.push_back(v);
        }
        for(int i=0;i<n;i++){
            mp[v1[i][0]]=i;
        }
        v2=v1;
        sort(v2.begin(),v2.end());
        bool cond=true;
        for(int i=0;i<n-1;i++){
            if(i==0){
                for(int j=0;j<v2[i].size()-1;j++){
                    if(v2[i][j]+n!=v2[i][j+1])cond=false;
                }
            }
            else{
                for(int j=0;j<m;j++){
                    if(v2[i+1][j]!=v2[i][j]+1)cond=false;
                    
                }
            }
        }

        if(!cond)cout<<-1<<endl;
        else {
            for(int i=0;i<n;i++){
                cout<<mp[v2[i][0]]+1<<" ";
            }
            cout<<endl;
        }

    }
}