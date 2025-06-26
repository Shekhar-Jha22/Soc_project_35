#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,c,d;
        cin>>n>>c>>d;
        vector<int>v;
        unordered_map<int,int>mp;
        for(int i=0;i<n*n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            if(mp[x]!=0)mp[x]++;
            else mp[x]=1;
        }

        sort(v.begin(),v.end());
        int a=v[0];
        bool cond=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!mp[a+i*c+j*d]){
                    cout<<"no"<<endl;
                    cond=false;
                    break;
                }
                else{
                    mp[a+i*c+j*d]--;
                }

            }
            if(!cond)break;
        }
        if(cond)cout<<"yes"<<endl;
    }
}