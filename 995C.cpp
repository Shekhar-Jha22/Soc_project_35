#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int > v;

        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        unordered_map<int,int> mp;

        for(int j=0;j<k;j++){
            
            mp[j+1]=0;
        }

        for(int j=0;j<k;j++){
            int x;
            cin>>x;
            mp[x]=1;
        }
        for(int j=0;j<m;j++){
            if(n==k)cout<<1;
            else if(k<n-1)cout<<0;
            else if(mp[v[j]])cout<<0;
            else cout<<1;
        }
        cout<<endl;

    }
}