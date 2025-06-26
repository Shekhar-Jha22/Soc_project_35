#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        int x=min(m/2,n/2);
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            vector<int>v1;
            for(int j=0;j<m;j++){
                int x;
                cin>>x;
                v1.push_back(x);

            }
            v.push_back(v1);
        }
        vector<vector<int>>v2;
        for(int i=0;i<x;i++){
            for(int j=i;j<n-i;j++){
                int x;
            }
        }
    }
}