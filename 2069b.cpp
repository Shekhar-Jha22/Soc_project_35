#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        unordered_map<int,bool>mp;
        vector<vector<int>>v;

        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int i=0;i<m;i++){
                int x;
                cin>>x;
                temp.push_back(x);
            }
            v.push_back(temp);
        }
        if(n==1 && m==1){
            cout<<0<<endl;
            continue;
        }
        else if(n==1){
            for(int j=0;j<m;j++){
                int i=0;
                if(mp[v[0][j]]!=true){
                    if(j==0 && (v[i][j]==v[i][j+1] ))mp[v[i][j]]=true;
                    else if(j==m-1 && v[i][j]==v[i][j-1] )mp[v[i][j]]=true;
                    else if(v[i][j]==v[i][j-1] || v[i][j]==v[i][j+1])mp[v[i][j]]=true;
                    else mp[v[i][j]]=false;
                }
            }
        }
        else if(m==1){
            for(int i=0;i<n;i++){
                int j=0;
                if(mp[v[j][0]]!=true){
                    if(i==0 && (v[i][j]==v[i+1][j] ))mp[v[i][j]]=true;
                    else if(i==n-1 && v[i][j]==v[i-1][j] )mp[v[i][j]]=true;
                    else if(v[i][j]==v[i+1][j] || v[i][j]==v[i-1][j])mp[v[i][j]]=true;
                    else mp[v[i][j]]=false;
                }
            }
        }
        else
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    if(mp[v[i][j]]!=true){
                        if(j==0 && (v[i][j]==v[i][j+1] || v[i][j]==v[i+1][j]))mp[v[i][j]]=true;
                        else if(j==m-1 && (v[i][j]==v[i][j-1] || v[i][j]==v[i+1][j]))mp[v[i][j]]=true;
                        else if(v[i][j]==v[i][j-1] || v[i][j]==v[i+1][j] || v[i][j]==v[i][j+1])mp[v[i][j]]=true;
                        else mp[v[i][j]]=false;
                    }
                }
                else if(i==n-1){
                    if(mp[v[i][j]]!=true){
                        if(j==0 && (v[i][j]==v[i][j+1] || v[i][j]==v[i-1][j]))mp[v[i][j]]=true;
                        else if(j==m-1 && (v[i][j]==v[i][j-1] || v[i][j]==v[i-1][j]))mp[v[i][j]]=true;
                        else if(v[i][j]==v[i][j-1] || v[i][j]==v[i-1][j] || v[i][j]==v[i][j+1])mp[v[i][j]]=true;
                        else mp[v[i][j]]=false;
                    }
                }
                else {
                    if(mp[v[i][j]]!=true){
                        if(v[i][j]==v[i][j-1] || v[i][j]==v[i-1][j] || v[i][j]==v[i][j+1] || v[i][j]==v[i+1][j])mp[v[i][j]]=true;
                        else mp[v[i][j]]=false;
                    }
                }
            }
        }
        int sum=0;
        bool bro=false;
        for(auto x:mp){
            if(x.second==true){
                sum+=2;
                bro=true;
            }
            else sum+=1;
        }
        if(bro)sum-=2;
        else sum-=1;
        cout<<sum<<endl;
    }
}